// Link: https://leetcode.com/problems/design-front-middle-back-queue/description/

#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    deque<int> d1, d2; // d1 front half, d2 back half; d1.size() == d2.size() or d1.size() == d2.size()+1

    FrontMiddleBackQueue() {}

    void balance() {
        while (d1.size() > d2.size() + 1) {
            d2.push_front(d1.back());
            d1.pop_back();
        }
        while (d2.size() > d1.size()) {
            d1.push_back(d2.front());
            d2.pop_front();
        }
    }

    void pushFront(int val) {
        d1.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (d1.size() == d2.size()) {
            d1.push_back(val);
        } else {
            d2.push_front(val);
        }
    }

    void pushBack(int val) {
        d2.push_back(val);
        balance();
    }

    int popFront() {
        if (d1.empty() && d2.empty()) return -1;
        int val;
        if (!d1.empty()) { val = d1.front(); d1.pop_front(); }
        else { val = d2.front(); d2.pop_front(); }
        balance();
        return val;
    }

    int popMiddle() {
        if (d1.empty() && d2.empty()) return -1;
        int val;
        if (d1.size() > d2.size()) { val = d1.back(); d1.pop_back(); }
        else { val = d2.front(); d2.pop_front(); }
        balance();
        return val;
    }

    int popBack() {
        if (d1.empty() && d2.empty()) return -1;
        int val;
        if (!d2.empty()) { val = d2.back(); d2.pop_back(); }
        else { val = d1.back(); d1.pop_back(); }
        balance();
        return val;
    }
};
