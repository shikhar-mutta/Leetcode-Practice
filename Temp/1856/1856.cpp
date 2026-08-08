// Link: https://leetcode.com/problems/maximum-subarray-min-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long sum = prefix[right[i]] - prefix[left[i] + 1];
            best = max(best, sum * nums[i]);
        }
        return (int)(best % MOD);
    }
};
