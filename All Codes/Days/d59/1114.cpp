// Link: https://leetcode.com/problems/print-in-order/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) as we are using constant space
// SC: O(1) as we are using constant space
//   Approach:
//    1. We can use three binary semaphores to control the access of the first, second, and third threads.
//    2. We can initialize the first semaphore with a value of 1 and the other two semaphores with a value of 0.
//    3. When the first thread is released, we acquire the first semaphore and release the second semaphore.
//    4. When the second thread is released, we acquire the second semaphore and release the third semaphore.
//    5. When the third thread is released, we acquire the third semaphore and print the output.
//    6. Finally, we return the answer which contains the maximum nesting depth of two valid parentheses strings.
class Foo
{
    sem_t s2, s3;

public:
    Foo()
    {
        sem_init(&s2, 0, 0);
        sem_init(&s3, 0, 0);
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        sem_post(&s2);
    }

    void second(function<void()> printSecond)
    {
        sem_wait(&s2);
        printSecond();
        sem_post(&s3);
    }

    void third(function<void()> printThird)
    {
        sem_wait(&s3);
        printThird();
    }
};