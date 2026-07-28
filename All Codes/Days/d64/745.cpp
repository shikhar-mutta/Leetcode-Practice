// Link: https://leetcode.com/problems/prefix-and-suffix-search/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (len(pref) + len(suff)))  SC: O(n * (len(pref) + len(suff)))
//  Approach: Trie. Store all suffixes of each word in a trie, with the index of the word at the end of each suffix. Then, for a query, traverse the trie with the suffix and then the prefix, returning the index of the word if found. If not found, return -1.

int dp[700009][27], totalUsed = 0;
class WordFilter
{
public:
    WordFilter(vector<string> &words)
    {
        int n = words.size();
        memset(dp, 0, sizeof(dp[0]) * totalUsed);
        totalUsed = 8;

        for (int wi = 0; wi < n; wi++)
        {
            string &s = words[wi];

            for (int len = 1; len <= s.size(); len++)
            {
                int i = len;
                for (auto it = end(s) - i; it != end(s); it++)
                {
                    int &j = dp[i][*it - 'a'];
                    if (!j)
                        j = ++totalUsed;
                    i = j;
                }

                for (char ch : s)
                {
                    int &j = dp[i][ch - 'a'];
                    if (!j)
                        j = ++totalUsed;
                    i = j;
                    dp[i][26] = wi;
                }
            }
        }
    }

    int f(string pref, string suff)
    {

        int i = suff.size();
        for (char ch : suff)
        {
            i = dp[i][ch - 'a'];
            if (!i)
                return -1;
        }

        for (char ch : pref)
        {
            i = dp[i][ch - 'a'];
            if (!i)
                return -1;
        }

        return dp[i][26];
    }
};
