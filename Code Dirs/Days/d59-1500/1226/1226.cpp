// Link: https://leetcode.com/problems/the-dining-philosophers/description/

#include <bits/stdc++.h>
using namespace std;

class DiningPhilosophers
{
    mutex mtx;
    condition_variable cv;
    vector<int> eaters;

public:
    // TC: O(1) as we are only performing a constant number of operations regardless of the input size.
    // SC: O(n) where n is the number of philosophers. We are using a vector to keep track of the philosophers who are currently eating, which can have a maximum size of n
    // Approach:
    // 1. We will use a mutex and a condition variable to synchronize access to the shared resource (the forks).
    // 2. When a philosopher wants to eat, they will acquire the mutex and check if any of their adjacent philosophers are currently eating. If so, they will wait on the condition variable until they are notified that they can eat.
    // 3. If none of their adjacent philosophers are eating, they will pick up the left and right forks, eat, and then put down the forks. They will then notify all waiting philosophers that they can check if they can eat.
    DiningPhilosophers() { eaters = {}; }

    void wantsToEat(int philosopher, function<void()> pickLeftFork,
                    function<void()> pickRightFork, function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {

        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this, philosopher]()
                {
            bool adjacentEating = false;
            for (auto eater : eaters) {
                if (abs(philosopher - eater) == 1) {
                    adjacentEating = true;
                    break;
                }
            }
            return !adjacentEating; });
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        cv.notify_all();
    }
};