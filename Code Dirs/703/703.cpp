// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogk) for constructor, O(logk) for add. SC: O(k) for the min-heap.
class KthLargest
{
    // Min-heap holding the k largest values seen so far; its top is the kth largest.
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int> &nums) : k(k)
    {
        for (int x : nums)
            add(x);
    }

    int add(int val)
    {
        minHeap.push(val);
        while ((int)minHeap.size() > k)
            minHeap.pop();
        return minHeap.top();
    }
};
