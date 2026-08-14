// Link: https://leetcode.com/problems/the-score-of-students-solving-math-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < (int)s.size(); i++) {
            if (isdigit(s[i])) nums.push_back(s[i] - '0');
            else ops.push_back(s[i]);
        }
        int n = nums.size();

        // correct answer via normal precedence
        vector<int> stackNums;
        stackNums.push_back(nums[0]);
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == '+') stackNums.push_back(nums[i + 1]);
            else stackNums.back() *= nums[i + 1];
        }
        int correct = accumulate(stackNums.begin(), stackNums.end(), 0);

        vector<vector<set<int>>> dp(n, vector<set<int>>(n));
        for (int i = 0; i < n; i++) dp[i][i].insert(nums[i]);
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int k = i; k < j; k++) {
                    char op = ops[k];
                    for (int a : dp[i][k]) {
                        for (int b : dp[k + 1][j]) {
                            long long val = (op == '+') ? (long long)a + b : (long long)a * b;
                            if (val <= 1000) dp[i][j].insert((int)val);
                        }
                    }
                }
            }
        }
        set<int>& possible = dp[0][n - 1];

        int score = 0;
        for (int ans : answers) {
            if (ans == correct) score += 5;
            else if (possible.count(ans)) score += 2;
        }
        return score;
    }
};
