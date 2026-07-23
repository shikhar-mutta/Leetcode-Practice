// Link: https://leetcode.com/problems/building-h2o/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of threads
// SC: O(1) as we are using constant space
//  Approach:
//   1. We can use two binary semaphores to control the access of hydrogen and oxygen threads.
//   2. We can use a counter to keep track of the number of hydrogen threads that have been released.
//   3. When a hydrogen thread is released, we increment the counter and check if it is odd or even. If it is odd, we release the hydrogen semaphore, otherwise we release the oxygen semaphore.
//   4. When an oxygen thread is released, we acquire the oxygen semaphore and release the hydrogen semaphore.
//   5. Finally, we return the answer which contains the maximum nesting depth of two valid parentheses strings.
class H2O
{
    int countH = 0;
    binary_semaphore h{1}, o{0};

public:
    H2O() {}
    void hydrogen(function<void()> releaseHydrogen)
    {
        h.acquire();
        releaseHydrogen();
        countH++;
        if (countH & 1)
        {
            h.release();
        }
        else
        {
            o.release();
        }
    }

    void oxygen(function<void()> releaseOxygen)
    {
        o.acquire();
        releaseOxygen();
        h.release();
    }
};