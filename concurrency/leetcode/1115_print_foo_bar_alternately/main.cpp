#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cond_var;
    bool turn = true;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock lock(mtx);
            cond_var.wait(lock, [&](){return turn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = false;
            cond_var.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock lock(mtx);
            cond_var.wait(lock, [&](){return !turn;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = true;
            cond_var.notify_all();
        }
    }
};

int main(int, char**){
    FooBar f (5);
    
    std::thread t1(std::bind(&FooBar::foo, &f, [](){std::cout<<"foo";}));
    std::thread t2(std::bind(&FooBar::bar, &f, [](){std::cout<<"bar" << std::endl;}));

    t1.join();
    t2.join();
}
