// Link: https://leetcode.com/problems/find-median-from-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) for addNum, O(1) for findMedian. SC: O(n) for storing the numbers in the heaps.
class MedianFinder
{
    std::priority_queue<int> left;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right;

public:
    void addNum(int num)
    {
        if (left.empty() || num <= left.top())
        {
            left.push(num);
        }
        else
        {
            right.push(num);
        }

        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
    }
    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;
        }
        return left.size() > right.size() ? left.top() : right.top();
    }
};