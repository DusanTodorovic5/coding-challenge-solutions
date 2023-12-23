# Problem

You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

 - Thread A: calls zero() that should only output 0's.
 - Thread B: calls even() that should only output even numbers.
 - Thread C: calls odd() that should only output odd numbers.

Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

 - ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
 - void zero(printNumber) Calls printNumber to output one zero.
 - void even(printNumber) Calls printNumber to output one even number.
 - void odd(printNumber) Calls printNumber to output one odd number.

# Code
```cpp
class ZeroEvenOdd {
private:
    int n;
    int index = -1;
    std::mutex mtx;
    std::condition_variable cond_var;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck(mtx);
            cond_var.wait(lck, [&]() { return index < 0; });
            if (index < -n) {
                index = -index;
                cond_var.notify_all();
                return;
            }

            printNumber(0);

            index = -index;
            cond_var.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck(mtx);
            cond_var.wait(lck, [&]() { return index > 0 && index % 2 == 0; });
            if (index > n) {
                ++index;
                cond_var.notify_all();
                return;
            }

            printNumber(index);

            index = -(++index);
            cond_var.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lck(mtx);
            cond_var.wait(lck, [&]() { return index > 0 && index % 2; });
            if (index > n) {
                ++index;
                cond_var.notify_all();
                return;
            }

            printNumber(index);

            index = -(++index);
            cond_var.notify_all();
        }
    }
};

```