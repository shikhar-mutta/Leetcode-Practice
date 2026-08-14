// Link: https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[nums[i]].push_back(i);
        int ans = INT_MAX;
        for (auto& [val, idxs] : pos) {
            int maxGap = idxs[0] + n - idxs.back();
            for (int i = 1; i < (int)idxs.size(); i++)
                maxGap = max(maxGap, idxs[i] - idxs[i-1]);
            ans = min(ans, maxGap / 2);
        }
        return ans;
    }
};
