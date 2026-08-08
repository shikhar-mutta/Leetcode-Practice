// Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.back() > nums[i] && (int)(st.size() - 1 + n - i) >= k) {
                st.pop_back();
            }
            if ((int)st.size() < k) st.push_back(nums[i]);
        }
        return st;
    }
};
