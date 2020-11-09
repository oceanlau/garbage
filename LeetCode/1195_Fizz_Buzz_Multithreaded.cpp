#include <semaphore.h>
class FizzBuzz {
private:
    int n;
    sem_t f_sem;
    sem_t b_sem;
    sem_t fb_sem;
    sem_t num_sem;
    bool stop = false;

public:
    FizzBuzz(int n) {
        this->n = n;
        sem_init(&f_sem, 0, 0);
        sem_init(&b_sem, 0, 0);
        sem_init(&fb_sem, 0, 0);
        sem_init(&num_sem, 0, 1);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            sem_wait(&f_sem);
            if (stop) {
                break;
            }
            printFizz();
            sem_post(&num_sem);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            sem_wait(&b_sem);
            if (stop) {
                break;
            }
            printBuzz();
            sem_post(&num_sem);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            sem_wait(&fb_sem);
            if (stop) {
                break;
            }
            printFizzBuzz();
            sem_post(&num_sem);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i ++) {
            sem_wait(&num_sem);
            if (i % 3 == 0 && i % 5 == 0) {
                sem_post(&fb_sem);
            } else if (i % 3 == 0) {
                sem_post(&f_sem);
            } else if (i % 5 == 0) {
                sem_post(&b_sem);
            } else {
                printNumber(i);
                sem_post(&num_sem);
            }
        }
        stop = true;
        sem_post(&fb_sem);
        sem_post(&f_sem);
        sem_post(&b_sem);
    }
};
