// Link: https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
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

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
        return ans;
    }
};
