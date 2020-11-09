#include <semaphore.h>
// Method 1: pick from left hand to right hand. Give up left hand if we found there
//           are no forks left to avoid dead lock
// Method 2: all or nothing
class DiningPhilosophers {
private:
    vector<bool> forks_available;
    mutex mu;
    vector<sem_t> philosophers;
    vector<bool> want_to_eat;
    
    void can_eat(int philosopher) {
        int left_fork = philosopher;
        int right_fork = philosopher == 0 ? 4 : philosopher - 1;
        if (want_to_eat[philosopher] && forks_available[left_fork] && forks_available[right_fork]) {
            forks_available[left_fork] = false;
            forks_available[right_fork] = false;
            want_to_eat[philosopher] = false;
            sem_post(&philosophers[philosopher]);
        }
    }
public:
    DiningPhilosophers() {
        forks_available.reserve(5);
        philosophers.reserve(5);
        want_to_eat.reserve(5);
        for (int i = 0; i < 5; i ++) {
            forks_available.push_back(true);
            sem_t phi_sem;
            philosophers.push_back(phi_sem);
            sem_init(&philosophers.back(), 0, 0);
            want_to_eat.push_back(false);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            unique_lock<mutex> lock(mu);
            want_to_eat[philosopher] = true;
            can_eat(philosopher);
        }
        sem_wait(&philosophers[philosopher]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        {
            unique_lock<mutex> lock(mu);
            int left_fork = philosopher;
            int right_fork = philosopher == 0 ? 4 : philosopher - 1;
            forks_available[left_fork] = true;
            forks_available[right_fork] = true;
            int left_philosopher = philosopher == 4 ? 0 : philosopher + 1;
            int right_philosopher = philosopher == 0 ? 4 : philosopher - 1;
            can_eat(left_philosopher);
            can_eat(right_philosopher);
        }
    }
};
