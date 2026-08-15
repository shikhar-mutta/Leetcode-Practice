// Link: https://leetcode.com/problems/print-foobar-alternately/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of threads
// SC: O(1) as we are using constant space
//   Approach:
//    1. We can use a mutex and condition variable to synchronize the threads.
//    2. We can use a boolean variable to keep track of whether it is the turn of the foo thread or the bar thread.
//    3. We can use a counter variable to keep track of the current number to be printed.
//    4. The foo thread will print "foo" and then signal the bar thread to print "bar".
//    5. The bar thread will print "bar" and then signal the foo thread to print "foo".
//    6. We will repeat this process until all numbers have been printed.
//    7. Finally, we return the answer which contains the maximum nesting depth of two valid parentheses strings.
class FooBar
{
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool fooTurn;

public:
    FooBar(int n)
    {
        this->n = n;
        fooTurn = true;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]
                    { return fooTurn; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            fooTurn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {
        for (int i = 0; i < n; i++)
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this]
                    { return !fooTurn; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            fooTurn = true;
            cv.notify_one();
        }
    }
};
