// Link: https://leetcode.com/problems/number-of-valid-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                count += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            count += n - st.top();
            st.pop();
        }
        return (int)count;
    }
};
