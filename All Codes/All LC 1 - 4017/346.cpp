// Link: https://leetcode.com/problems/moving-average-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized next()  SC: O(size)
// Approach: sliding window queue with running sum, evict oldest when full
class MovingAverage {
    queue<int> q;
    int cap;
    double sum = 0;

public:
    MovingAverage(int size) : cap(size) {}

    double next(int val) {
        q.push(val);
        sum += val;
        if ((int)q.size() > cap) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};
