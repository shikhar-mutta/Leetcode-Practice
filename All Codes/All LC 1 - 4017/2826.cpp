// Link: https://leetcode.com/problems/sorting-three-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: min changes = n minus the longest non-decreasing subsequence
// (elements outside it get overwritten). Since values are only 1/2/3,
// dp[v] = longest such subsequence ending on value v+1, updated as
// max(dp[0..v]) + 1 for each element (only values <= current can precede it
// in a non-decreasing run).
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // dp[v] = longest non-decreasing subsequence ending with value v+1
        int dp[3] = {0, 0, 0};

        for (int x : nums) {
            // x is 1, 2, or 3 (0-indexed: 0, 1, 2)
            int v = x - 1;
            // extending the longest subsequence ending at value <= v
            dp[v] =
                max({dp[0], (v >= 1 ? dp[1] : 0), (v >= 2 ? dp[2] : 0)}) + 1;
        }
        int longest = max({dp[0], dp[1], dp[2]});
        return nums.size() - longest;
    }
};
