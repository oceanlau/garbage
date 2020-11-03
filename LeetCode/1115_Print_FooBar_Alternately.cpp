class FooBar {
private:
    int n;
    
    bool is_foo_step = true;
    condition_variable cv;
    mutex mu;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [&]{return is_foo_step;});
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            is_foo_step = false;
            lock.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mu);
            cv.wait(lock, [&]{return !is_foo_step;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            is_foo_step = true;
            lock.unlock();
            cv.notify_one();
        }
    }
};

#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t sem_foo;
    sem_t sem_bar;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&sem_foo, 0, 1);
        sem_init(&sem_bar, 0, 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem_foo);
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            
            sem_post(&sem_bar);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(&sem_bar);
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            sem_post(&sem_foo);
        }
    }
};
