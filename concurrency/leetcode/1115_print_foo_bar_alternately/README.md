# Problem

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

# Code
```cpp
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
```
>Ideal: Use 2 semaphores and foo locks foo_sem, unlocks bar_sem and vice versa for bar.