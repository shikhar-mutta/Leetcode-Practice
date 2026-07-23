// Link: https://leetcode.com/problems/fizz-buzz-multithreaded/description/

#include <bits/stdc++.h>
using namespace std;

class FizzBuzz
{
    int n, cur = 1;
    mutex mtx;
    condition_variable cv;

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