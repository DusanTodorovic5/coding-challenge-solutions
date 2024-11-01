#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable>

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

ZeroEvenOdd zeo(2);

void zero() {
    zeo.zero([](int x){std::cout<<x;});
}

void odd() {
    zeo.odd([](int x){std::cout<<x;});
}

void even() {
    zeo.even([](int x){std::cout<<x;});
}

int main(int, char**){
    std::thread t1(zero);
    std::thread t2(odd);
    std::thread t3(even);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}