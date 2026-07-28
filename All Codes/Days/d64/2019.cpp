// Link: https://leetcode.com/problems/the-score-of-students-solving-math-expression/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^4) for the interval DP (n = token count, small)  SC: O(n^2)
// Approach: tokenize into numbers/operators. Compute the true answer via
// standard precedence evaluation. Separately, interval DP over all possible
// bracketings/orderings of operations enumerates every value a student could
// reach by evaluating naively left-to-right in some split order (capped at
// 1000). Score 5 for the correct answer, 2 for any other reachable value,
// else 0.
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        vector<int> nums;
        vector<char> ops;
        int i = 0, n = s.size();
        while (i < n) {
            int v = 0;
            while (i < n && isdigit(s[i])) { v = v * 10 + (s[i] - '0'); i++; }
            nums.push_back(v);
            if (i < n) { ops.push_back(s[i]); i++; }
        }
        int m = nums.size();

        // true evaluation (precedence)
        vector<int> stk;
        stk.push_back(nums[0]);
        for (int k = 0; k < (int)ops.size(); k++) {
            if (ops[k] == '*') stk.back() *= nums[k+1];
            else stk.push_back(nums[k+1]);
        }
        int correct = 0;
        for (int v : stk) correct += v;

        vector<vector<set<int>>> dp(m, vector<set<int>>(m));
        for (int idx = 0; idx < m; idx++) dp[idx][idx].insert(nums[idx]);
        for (int len = 2; len <= m; len++) {
            for (int l = 0; l + len - 1 < m; l++) {
                int r = l + len - 1;
                for (int k = l; k < r; k++) {
                    char op = ops[k];
                    for (int a : dp[l][k]) {
                        for (int b : dp[k+1][r]) {
                            int val = (op == '+') ? a + b : a * b;
                            if (val <= 1000) dp[l][r].insert(val);
                        }
                    }
                }
            }
        }

        auto& possible = dp[0][m-1];
        int score = 0;
        for (int ans : answers) {
            if (ans == correct) score += 5;
            else if (possible.count(ans)) score += 2;
        }
        return score;
    }
};
