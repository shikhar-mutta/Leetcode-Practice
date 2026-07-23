// Link: https://leetcode.com/problems/the-dining-philosophers/description/

#include <bits/stdc++.h>
using namespace std;

class DiningPhilosophers
{
    mutex mtx;
    condition_variable cv;
    vector<int> eaters;

public:
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