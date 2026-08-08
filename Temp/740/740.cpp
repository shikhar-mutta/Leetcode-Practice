// Link: https://leetcode.com/problems/delete-and-earn/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + maxVal) SC: O(maxVal)
// Approach: bucket total points per value (value * count), then run house-robber DP over consecutive values (taking value v excludes v-1 and v+1).
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<long long> points(maxVal+1, 0);
        for (int x : nums) points[x] += x;
        long long take = 0, skip = 0;
        for (int v = 0; v <= maxVal; v++) {
            long long newTake = skip + points[v];
            long long newSkip = max(take, skip);
            take = newTake;
            skip = newSkip;
        }
        return (int)max(take, skip);
    }
};
