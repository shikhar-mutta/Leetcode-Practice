// Link: https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        vector<pair<int,long long>> st; // (value, count)
        long long ans = 0;
        for (int num : nums) {
            while (!st.empty() && st.back().first < num) st.pop_back();
            if (st.empty() || st.back().first != num) {
                st.push_back({num, 1});
                ans += 1;
            } else {
                st.back().second++;
                ans += st.back().second;
            }
        }
        return ans;
    }
};
