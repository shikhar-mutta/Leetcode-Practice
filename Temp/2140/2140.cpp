// Link: https://leetcode.com/problems/solving-questions-with-brainpower/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long skip = dp[i + 1];
            int nxt = i + questions[i][1] + 1;
            long long take = questions[i][0] + (nxt < n ? dp[nxt] : 0);
            dp[i] = max(skip, take);
        }
        return dp[0];
    }
};
