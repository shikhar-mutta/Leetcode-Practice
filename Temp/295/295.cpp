// Link: https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) addNum, O(1) findMedian  SC: O(n)
// Approach: two heaps - max-heap for lower half, min-heap for upper half,
// keep sizes balanced (lower can have at most one more than upper)
class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

public:
    MedianFinder() {}

    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if (hi.size() > lo.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};
