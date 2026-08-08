// Link: https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const long long MOD = 1e9 + 7;
        int n = nextVisit.size();
        vector<long long> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = ((2 * dp[i-1] - dp[nextVisit[i-1]] + 2) % MOD + MOD) % MOD;
        }
        return (int)dp[n-1];
    }
};
