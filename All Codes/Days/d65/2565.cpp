// Link: https://leetcode.com/problems/subsequence-with-the-minimum-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: We can use a two pointer approach to solve this problem. We can keep track of the suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence.
class Solution
{
public:
    int minimumScore(string s, string t)
    {
        int ss = s.length(), ts = t.length();
        int i = ss - 1, j = ts - 1, k = ts - 1; // i for ss, j for t , k for dp

        vector<int> dp(ts, -1);
        for (; i >= 0; i--)
        {
            if (j >= 0 && s[i] == t[j])
            {
                dp[k] = i;
                k--;
                j--;
            }
        }

        int result =
            k + 1; // since k will be one place behind the actual suffix
        if (result == 0)
            return 0;
        k = result;
        j = 0;
        for (int i = 0; i <= ss - 1; i++)
        {
            if (j < ts && t[j] == s[i])
            {
                while (k < ts && dp[k] <= i)
                    k++;

                result = min(result, k - j - 1);
                //(k - 1) - (j + 1) + 1= k - j - 1
                j++;
            }
        }
        return result;
    }
};
