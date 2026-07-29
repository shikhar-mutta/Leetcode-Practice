// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * m) SC: O(m)
//  Approach: We can use dynamic programming to count the number of ways to form the target string. We first count the frequency of each character at each position in the words. Then, we use a DP array to keep track of the number of ways to form the target string up to each position in the words. We iterate through the words and update the DP array based on the character frequencies and the previous counts.
class Solution
{
public:
    int numWays(vector<string> &words, string target)
    {
        int k = words[0].size();
        int m = target.size();
        long long P = 1e9 + 7;

        // OPTIMIZATION 3: Use array<int, 26> for better cache locality compared to vector<int>
        vector<array<int, 26>> freq(k, {0});

        for (const string &word : words)
        {
            for (int j = 0; j < k; j++)
            {
                freq[j][word[j] - 'a']++;
            }
        }

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= k; i++)
        {
            // OPTIMIZATION 1: Strict loop bounds (Pruning)
            int min_j = max(1, m - k + i);
            int max_j = min(m, i);

            for (int j = max_j; j >= min_j; j--)
            {
                long long count = freq[i - 1][target[j - 1] - 'a'];

                // OPTIMIZATION 2: Skip expensive modulo operations if count is 0
                if (count > 0)
                {
                    dp[j] = (dp[j] + count * dp[j - 1]) % P;
                }
            }
        }

        return dp[m];
    }
};
