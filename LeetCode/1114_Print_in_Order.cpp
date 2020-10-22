class Foo {
private:
    int step = 1;
    condition_variable cv;
    mutex m;
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        step = 2;
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return step == 2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step = 3;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return step == 3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
