// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // min-heap holds the k largest elements seen so far; its top is the kth largest
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if ((minHeap.size() < k))
            {
                // still filling up to k elements
                minHeap.push(nums[i]);
            }
            else if ((minHeap.top() < nums[i]))
            {
                // nums[i] beats the current smallest of the top-k, swap it in
                minHeap.push(nums[i]);
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
