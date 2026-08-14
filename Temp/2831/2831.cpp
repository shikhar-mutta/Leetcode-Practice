// Link: https://leetcode.com/problems/find-the-longest-equal-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < (int)nums.size(); i++) pos[nums[i]].push_back(i);
        int ans = 0;
        for (auto& [val, idxs] : pos) {
            int l = 0;
            for (int r = 0; r < (int)idxs.size(); r++) {
                while ((idxs[r] - idxs[l] + 1) - (r - l + 1) > k) l++;
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
