// Link: https://leetcode.com/problems/design-circular-deque/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per op SC: O(k)
// Approach: fixed-size array with head index and count; insertFront decrements head (mod cap), insertLast writes at (head+count)%cap.
class MyCircularDeque {
    vector<int> buf;
    int head = 0, cnt = 0, cap;
public:
    MyCircularDeque(int k) : buf(k), cap(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        head = (head - 1 + cap) % cap;
        buf[head] = value;
        cnt++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        buf[(head+cnt) % cap] = value;
        cnt++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        head = (head+1) % cap;
        cnt--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        cnt--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buf[head];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return buf[(head+cnt-1) % cap];
    }

    bool isEmpty() { return cnt == 0; }

    bool isFull() { return cnt == cap; }
};
