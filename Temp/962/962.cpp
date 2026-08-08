// Link: https://leetcode.com/problems/maximum-width-ramp/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.back()] > nums[i]) st.push_back(i);
        }
        int best = 0;
        for (int j = n - 1; j >= 0; j--) {
            while (!st.empty() && nums[st.back()] <= nums[j]) {
                best = max(best, j - st.back());
                st.pop_back();
            }
        }
        return best;
    }
};
