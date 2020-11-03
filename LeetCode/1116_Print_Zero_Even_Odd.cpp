class ZeroEvenOdd {
private:
    int n;
    
    bool is_zero_turn = true;
    int num = 0;
    mutex mu;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i ++) {
            {
                unique_lock<mutex> lock(mu);
                cv.wait(lock, [&]{return is_zero_turn;});
                printNumber(0);
                is_zero_turn = false;
                num ++;
            }
            cv.notify_all();
        }
        
    }

    void even(function<void(int)> printNumber) {
        for (int i = 0; i < n / 2; i ++) {
            {
                unique_lock<mutex> lock(mu);
                cv.wait(lock, [&]{return !is_zero_turn && num % 2 == 0;});
                printNumber(num);
                is_zero_turn = true;
            }
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 0; i < (n + 1) / 2; i ++) {
            {
                unique_lock<mutex> lock(mu);
                cv.wait(lock, [&]{return !is_zero_turn && num % 2 == 1;});
                printNumber(num);
                is_zero_turn = true;
            }
            cv.notify_all();
        }
    }
};
