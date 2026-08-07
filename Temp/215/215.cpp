// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) average  SC: O(log n)
// Approach: min-heap of size k, push all elements, pop when heap exceeds k, top is the kth largest
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : nums) {
            pq.push(x);
            if ((int)pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
