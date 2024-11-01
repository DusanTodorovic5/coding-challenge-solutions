# Problem

Suppose we have a class:

```cpp

class Foo {
    void first() { print("first"); }
    void second() { print("second"); }
    void third() { print("third"); }
}

```
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

# Code
```cpp
class FooConditionalVariable {
public:
    FooConditionalVariable() : print_index(1) {

    }

    void first(std::function<void()> printFirst) {
        std::unique_lock scoped_lock(lock);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        print_index = 2;
        cond_var.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock scoped_lock(lock);
        cond_var.wait(scoped_lock, [&](){return print_index == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        print_index = 3;
        cond_var.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock scoped_lock(lock);
        cond_var.wait(scoped_lock, [&](){return print_index == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        print_index = 1;
        cond_var.notify_all();
    }
private:
    std::mutex lock;
    std::condition_variable cond_var;
    int print_index;
};

class Foo {
public:
    Foo() {
        first_lock.lock();
        second_lock.lock();
    }

    void first(std::function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_lock.unlock();
    }

    void second(std::function<void()> printSecond) {
        first_lock.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        second_lock.unlock();
    }

    void third(std::function<void()> printThird) {
        second_lock.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    std::mutex first_lock;
    std::mutex second_lock;
};
```