// Link: https://leetcode.com/problems/design-front-middle-back-queue/description/

#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
    deque<int> dq;

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) { dq.push_front(val); }
    void pushBack(int val) { dq.push_back(val); }

    void pushMiddle(int val) {
        // two middles -> insert at the frontmost: index size/2
        dq.insert(dq.begin() + dq.size() / 2, val);
    }

    int popFront() {
        if (dq.empty()) return -1;
        int v = dq.front();
        dq.pop_front();
        return v;
    }

    int popMiddle() {
        if (dq.empty()) return -1;
        // two middles -> pop the frontmost: index (size-1)/2
        int idx = (dq.size() - 1) / 2;
        int v = dq[idx];
        dq.erase(dq.begin() + idx);
        return v;
    }

    int popBack() {
        if (dq.empty()) return -1;
        int v = dq.back();
        dq.pop_back();
        return v;
    }
};
