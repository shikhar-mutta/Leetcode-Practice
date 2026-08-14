// Link: https://leetcode.com/problems/maximum-total-reward-using-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        const int SZ = 100005;
        bitset<SZ> dp;
        dp[0] = 1;
        bitset<SZ> allOnes;
        allOnes.set();
        for (int v : rewardValues) {
            if (v >= SZ) continue;
            bitset<SZ> mask = allOnes >> (SZ - v); // bits [0, v-1] set
            bitset<SZ> low = dp & mask;
            dp |= (low << v);
        }
        for (int s = SZ - 1; s >= 0; s--) if (dp[s]) return s;
        return 0;
    }
};
