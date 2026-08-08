// Link: https://leetcode.com/problems/last-stone-weight-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int s : stones) {
            for (int j = target; j >= s; j--) {
                if (dp[j - s]) dp[j] = true;
            }
        }
        int best = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[j]) { best = j; break; }
        }
        return total - 2 * best;
    }
};
