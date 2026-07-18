// Link: https://leetcode.com/problems/design-circular-queue/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1). SC: O(k).
class MyCircularQueue
{
    vector<int> q;
    int head, count, cap;

public:
    MyCircularQueue(int k) : q(k), head(0), count(0), cap(k) {}

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        q[(head + count) % cap] = value;
        count++;
        return true;
    }
    bool deQueue()
    {
        if (isEmpty())
            return false;
        head = (head + 1) % cap;
        count--;
        return true;
    }
    int Front() { return isEmpty() ? -1 : q[head]; }
    int Rear() { return isEmpty() ? -1 : q[(head + count - 1) % cap]; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == cap; }
};
