// Link: https://leetcode.com/problems/find-the-value-of-the-partition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        for (int i = 1; i < (int)nums.size(); i++) best = min(best, nums[i] - nums[i-1]);
        return best;
    }
};
