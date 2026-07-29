// Link: https://leetcode.com/problems/the-score-of-students-solving-math-expression/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
//  Approach: Use dynamic programming to calculate all possible results of the expression by considering all possible ways to parenthesize the expression. Store the results in a 2D vector of unordered sets. Then, for each answer in the answers vector, check if it matches the correct value or if it is present in the set of possible results. Calculate the score based on the matching criteria.
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
class Solution
{
public:
    int scoreOfStudents(string s, vector<int> &answers)
    {
        int correct_val = 0;
        vector<int> st = {};
        st.push_back(s[0] - '0');
        for (int i = 1; i < s.length(); i += 2)
        {
            char op = s[i];
            int val = s[i + 1] - '0';
            if (op == '*')
            {
                st.back() *= val;
            }
            else
            {
                st.push_back(val);
            }
        }
        for (int x : st)
        {
            correct_val += x;
        }

        int m = (s.length() + 1) / 2;
        vector<int> val(m);
        vector<char> op(m - 1);
        for (int i = 0; i < m; ++i)
        {
            val[i] = s[2 * i] - '0';
        }
        for (int i = 0; i < m - 1; ++i)
        {
            op[i] = s[2 * i + 1];
        }

        vector<vector<unordered_set<int>>> dp(m, vector<unordered_set<int>>(m));
        for (int i = 0; i < m; ++i)
        {
            dp[i][i].insert(val[i]);
        }
        for (int len = 2; len <= m; ++len)
        {
            for (int i = 0; i <= m - len; ++i)
            {
                int j = i + len - 1;
                for (int k = i; k < j; ++k)
                {
                    char o = op[k];
                    for (int x : dp[i][k])
                    {
                        for (int y : dp[k + 1][j])
                        {
                            int res_val = (o == '+') ? (x + y) : (x * y);
                            if (res_val <= 1000)
                            {
                                dp[i][j].insert(res_val);
                            }
                        }
                    }
                }
            }
        }

        vector<bool> possible(1005, false);
        for (int x : dp[0][m - 1])
        {
            if (x <= 1000)
            {
                possible[x] = true;
            }
        }

        int score = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            int ans = answers[i];
            if (ans == correct_val)
            {
                score += 5;
            }
            else if (possible[ans])
            {
                score += 2;
            }
        }

        return score;
    }
};
