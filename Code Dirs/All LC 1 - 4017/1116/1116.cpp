// Link: https://leetcode.com/problems/print-zero-even-odd/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of threads
// SC: O(1) as we are using constant space
//   Approach:
//    1. We can use a mutex and condition variable to synchronize the threads.
//    2. We can use a boolean variable to keep track of whether it is the turn of the zero thread or the even/odd thread.
//    3. We can use a counter variable to keep track of the current number to be printed.
//    4. The zero thread will print 0 and then signal the even/odd thread to print the next number.
//    5. The even/odd thread will print the current number and then signal the zero thread to print the next 0.
//    6. We will repeat this process until all numbers have been printed.
//    7. Finally, we return the answer which contains the maximum nesting depth of two valid parentheses strings.
class ZeroEvenOdd
{
    int n;
    int cur = 1;
    bool zeroTurn = true;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) : n(n) {}

    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return zeroTurn; });
            printNumber(0);
            zeroTurn = false;
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return (!zeroTurn && cur % 2 == 0) || cur > n; });
            if (cur > n)
                return;
            printNumber(cur++);
            zeroTurn = true;
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return (!zeroTurn && cur % 2 == 1) || cur > n; });
            if (cur > n)
                return;
            printNumber(cur++);
            zeroTurn = true;
            lk.unlock();
            cv.notify_all();
        }
    }
};