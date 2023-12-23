#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

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

int main(int, char**){
    std::cout << "Hello, from 1114_print_in_order!\n";
}
