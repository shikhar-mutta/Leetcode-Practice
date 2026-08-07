// Link: https://leetcode.com/problems/design-circular-queue/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per op SC: O(k)
// Approach: fixed-size array with head index and count; enqueue writes at (head+count)%k, dequeue advances head.
class MyCircularQueue {
    vector<int> buf;
    int head = 0, cnt = 0, cap;
public:
    MyCircularQueue(int k) : buf(k), cap(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        buf[(head+cnt) % cap] = value;
        cnt++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head+1) % cap;
        cnt--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buf[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return buf[(head+cnt-1) % cap];
    }

    bool isEmpty() { return cnt == 0; }

    bool isFull() { return cnt == cap; }
};
