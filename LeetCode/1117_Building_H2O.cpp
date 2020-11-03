// Tricky part is H and O must make progress together
// So we need a pass_barrier bool
class H2O {
private:
    int h = 0;
    int o = 0;
    bool pass_barrier = false;
    int h_to_consume = 0;
    int o_to_consume = 0;
    mutex mu;
    condition_variable cv;
public:
    H2O() {
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mu);
        h ++;
        cv.wait(lock, [&]{
            return (!pass_barrier && h > 1 && o > 0) || (pass_barrier && h_to_consume > 0);
        });
        h --;
        if (h_to_consume > 0) {
            h_to_consume --;
            if (h_to_consume == 0 && o_to_consume == 0) {
                pass_barrier = false;
            }
        } else {
            h_to_consume += 1;
            o_to_consume += 1;
            pass_barrier = true;
        }
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        lock.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mu);
        o ++;
        cv.wait(lock, [&]{
            return (!pass_barrier && h > 1 && o > 0) || (pass_barrier && o_to_consume > 0);
        });
        o --;
        if (o_to_consume > 0) {
            o_to_consume --;
            if (h_to_consume == 0 && o_to_consume == 0) {
                pass_barrier = false;
            }
        } else {
            // We dont have this problem if we use the pass_barrier bool:
            // Consider HHHHHHOOO
            // When first O came in, we should consume 2 H
            // But the new O might get the lock before cv
            // Then this h_to_consume would be overwritten
            h_to_consume += 2;
            pass_barrier = true;
        }
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        lock.unlock();
        cv.notify_all();
    }
};
