// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<long long> dp = {0, LLONG_MIN, LLONG_MIN};
        for (int x : nums) {
            vector<long long> next = dp;
            for (int r = 0; r < 3; r++) {
                if (dp[r] == LLONG_MIN) continue;
                int nr = (r + x) % 3;
                next[nr] = max(next[nr], dp[r] + x);
            }
            dp = next;
        }
        return (int)dp[0];
    }
};
