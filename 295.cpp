// Link: https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> lo;                            // max-heap, smaller half
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap, larger half

    MedianFinder() {}

    void addNum(int num)
    {
        lo.push(num);              // push to max heap
        hi.push(lo.top());         // balancing step
        lo.pop();                  // make sure every num in lo is <= every num in hi
        if (hi.size() > lo.size()) // maintain size property
        {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian()
    {
        if (lo.size() > hi.size()) // odd case
            return lo.top();
        return (lo.top() + hi.top()) / 2.0; // even case
    }
};
