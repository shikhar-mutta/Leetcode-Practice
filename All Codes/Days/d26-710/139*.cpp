// Link: https://leetcode.com/problems/word-break/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * m). SC: O(n).
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     int n = s.size();
    //     // dp[i] = true if s[0..i) can be segmented into dict words
    //     vector<bool> dp(n + 1, false);
    //     dp[0] = true;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (dp[j] && dict.count(s.substr(j, i - j)))
    //             {
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[n];
    // }

    
    // TC: O(n^2 * m). SC: O(n).
    bool solve(int idx, string &s, vector<string> &wordDict, vector<int> &dp)
    {
        if (idx == s.size()) // base case: reached the end of the string
            return true;

        if (dp[idx] != -1) // if already computed, return the stored result
            return dp[idx];

        for (string &word : wordDict)
        { // check if the word can fit in the remaining substring
            int len = word.size();
            if (idx + len <= s.size() &&
                s.substr(idx, len) == word)
            {
                if (solve(idx + len, s, wordDict, dp))
                    return dp[idx] = true; // if the rest of the string can be segmented, mark as true
            }
        }
        return dp[idx] = false; // if no word fits, mark as false
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> dp(s.size(), -1);     // -1: unvisited, 0: false, 1: true
        return solve(0, s, wordDict, dp); // start from index 0
    }
};