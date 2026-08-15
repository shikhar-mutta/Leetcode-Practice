// Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>* numsPtr;
    int target;
    vector<vector<int>> memo;

    int solve(int i, int j) {
        if (i >= j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        auto& nums = *numsPtr;
        int best = 0;
        if (nums[i] + nums[i+1] == target) best = max(best, 1 + solve(i+2, j));
        if (nums[j-1] + nums[j] == target) best = max(best, 1 + solve(i, j-2));
        if (nums[i] + nums[j] == target) best = max(best, 1 + solve(i+1, j-1));
        memo[i][j] = best;
        return best;
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        numsPtr = &nums;
        int best = 0;

        vector<int> targets = {nums[0]+nums[1], nums[n-2]+nums[n-1], nums[0]+nums[n-1]};
        for (int t : targets) {
            target = t;
            memo.assign(n, vector<int>(n, -1));
            best = max(best, solve(0, n-1));
        }
        return best;
    }
};
