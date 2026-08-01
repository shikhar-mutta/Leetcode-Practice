// Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: sort nums, dp[v] = longest consecutive run ending at value v
// achievable so far. For each num in sorted order: first extend
// dp[num+1] = dp[num] + 1 (using num's +1 modification), using the OLD
// dp[num] before it's updated this iteration; then extend
// dp[num] = dp[num-1] + 1 (using num as-is). Answer is max over all dp.
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;
        int ans = 1;
        for (int num : nums) {
            int viaPlus1 = dp.count(num) ? dp[num] + 1 : 1;
            int viaAsIs = dp.count(num - 1) ? dp[num - 1] + 1 : 1;
            dp[num + 1] = max(dp.count(num + 1) ? dp[num + 1] : 0, viaPlus1);
            dp[num] = max(dp.count(num) ? dp[num] : 0, viaAsIs);
            ans = max({ans, dp[num], dp[num + 1]});
        }
        return ans;
    }
};
