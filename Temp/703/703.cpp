// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log k) per add SC: O(k)
// Approach: maintain a min-heap of size k; the kth largest is always the heap top.
class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int x : nums) add(x);
    }

    int add(int val) {
        pq.push(val);
        if ((int)pq.size() > k) pq.pop();
        return pq.top();
    }
};
