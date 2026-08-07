// Link: https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m)  SC: O(n)
// Approach: monotonic decreasing stack over nums2, pop and record next
// greater for each element, then look up for nums1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> stk;
        for (int x : nums2) {
            while (!stk.empty() && stk.top() < x) {
                nextGreater[stk.top()] = x;
                stk.pop();
            }
            stk.push(x);
        }
        vector<int> res;
        for (int x : nums1) res.push_back(nextGreater.count(x) ? nextGreater[x] : -1);
        return res;
    }
};
