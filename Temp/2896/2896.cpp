// Link: https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> diffs;
        for (int i = 0; i < (int)s1.size(); i++)
            if (s1[i] != s2[i]) diffs.push_back(i);
        int m = diffs.size();
        if (m % 2 != 0) return -1;
        if (m == 0) return 0;
        vector<long long> dp(m + 1, 0);
        dp[1] = x;
        for (int i = 2; i <= m; i++) {
            dp[i] = dp[i - 1] + x;
            dp[i] = min(dp[i], dp[i - 2] + min((long long)x, (long long)(diffs[i - 1] - diffs[i - 2])));
        }
        return (int)dp[m];
    }
};
