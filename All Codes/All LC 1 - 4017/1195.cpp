// Link: https://leetcode.com/problems/fizz-buzz-multithreaded/description/

#include <bits/stdc++.h>
using namespace std;

class FizzBuzz
{
    int n, cur = 1;
    mutex mtx;
    condition_variable cv;
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. Use a mutex and condition variable to synchronize access to the shared variable cur
    //  2. Each thread will wait until it's their turn to print based on the value of cur and the divisibility conditions for fizz, buzz, and fizzbuzz.
    //  3. The number thread will print the current number if it's not divisible by 3 or 5, and then increment cur and notify all threads to check if it's their turn.
    // 4. The fizz, buzz, and fizzbuzz threads will print their respective strings if the current number is divisible by 3, 5, or both, and then increment cur and notify all threads to check if it's their turn.
    //  5. The process continues until cur exceeds n, at which point all threads will exit.
    void run(int mod3, int mod5, function<void()> print)
    {
        while (true)
        {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return cur > n ||
                             ((cur % 3 == 0) == mod3 && (cur % 5 == 0) == mod5); });
            if (cur > n)
                return;
            print();
            cur++;
            lk.unlock();
            cv.notify_all();
        }
    }

public:
    FizzBuzz(int n) : n(n) {}

    void fizz(function<void()> printFizz) { run(1, 0, printFizz); }
    void buzz(function<void()> printBuzz) { run(0, 1, printBuzz); }
    void fizzbuzz(function<void()> printFizzBuzz) { run(1, 1, printFizzBuzz); }

    void number(function<void(int)> printNumber)
    {
        while (true)
        {
            unique_lock<mutex> lk(mtx);
            cv.wait(lk, [&]
                    { return cur > n || (cur % 3 && cur % 5); });
            if (cur > n)
                return;
            printNumber(cur);
            cur++;
            lk.unlock();
            cv.notify_all();
        }
    }
};