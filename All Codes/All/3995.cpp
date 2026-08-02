// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * l)  SC: O(n)
//  Approach: We can use dynamic programming to solve this problem. We can use a dp array to store the minimum cost to convert the source string to the target string. We can iterate through the source string and for each character, we can check if it matches the target string. If it matches, we can move to the next character. If it doesn't match, we can check if there is a rule that can be applied to convert the source character to the target character. If there is a rule, we can apply the rule and update the dp array accordingly. Finally, we return the minimum cost to convert the source string to the target string.
class Solution
{
public:
    int minCost(string source, string target, vector<vector<string>> &rules, vector<int> &costs)
    {
        if (source.size() != target.size())
            return -1;
        if (source == target)
            return 0;

        int n = source.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);

        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == INF)
                continue;

            if (source[i] == target[i])
            {
                dp[i + 1] = min(dp[i + 1], dp[i]);
                ;
            }

            for (int j = 0; j < rules.size(); j++)
            {
                const string &p = rules[j][0], &r = rules[j][1];
                int len = p.size();

                if (i + len > n)
                    continue;

                bool valid = true;
                int cnt = 0;

                for (int l = 0; l < len; l++)
                {
                    if (p[l] == '*')
                        cnt++;
                    else if (p[l] != source[i + l])
                    {
                        valid = false;
                        break;
                    }

                    if (r[l] != target[i + l])
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    dp[i + len] = min(dp[i + len], dp[i] + costs[j] + cnt);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};
