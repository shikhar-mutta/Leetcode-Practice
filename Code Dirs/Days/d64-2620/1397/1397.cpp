// Link: https://leetcode.com/problems/find-all-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * 26) SC: O(n * m)
// Approach: DP + KMP
//  We can solve this problem using dynamic programming and KMP algorithm. The idea is to use a 3D DP array where dp[i][j][k] represents the number of good strings of length i that have matched j characters of the evil string and are in state k (where k = 0 means the string is less than s1, k = 1 means the string is greater than s2, and k = 2 means the string is between s1 and s2). We can use KMP algorithm to build the prefix function for the evil string and use it to transition between states. Finally, we return the value of dp[n][0][3] which represents the number of good strings of length n that have not matched any characters of the evil string and are in state 3 (between s1 and s2).
class Solution
{
public:
    static const int MOD = 1e9 + 7;
    int n, m;
    string s1, s2, evil;
    int lps[55];
    int trans[55][26];
    int dp[505][55][4];
    // Build KMP prefix function
    void buildLPS()
    {
        lps[0] = 0;
        int j = 0;
        for (int i = 1; i < m; i++)
        {
            while (j > 0 && evil[i] != evil[j])
                j = lps[j - 1];
            if (evil[i] == evil[j])
                j++;
            lps[i] = j;
        }
    }
    // Build automaton
    void buildTransition()
    {
        for (int state = 0; state <= m; state++)
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (state == m)
                {
                    trans[state][ch - 'a'] = m;
                    continue;
                }
                int j = state;
                while (j > 0 && evil[j] != ch)
                    j = lps[j - 1];
                if (evil[j] == ch)
                    j++;
                trans[state][ch - 'a'] = j;
            }
        }
    }
    int dfs(int pos, int matched, int state)
    {
        if (matched == m)
            return 0;
        if (pos == n)
            return 1;
        if (dp[pos][matched][state] != -1)
            return dp[pos][matched][state];
        bool low = state & 2;
        bool high = state & 1;
        char L = low ? s1[pos] : 'a';
        char R = high ? s2[pos] : 'z';
        long long ans = 0;
        for (char ch = L; ch <= R; ch++)
        {
            int nxtMatched = trans[matched][ch - 'a'];
            int newLow = low && (ch == s1[pos]);
            int newHigh = high && (ch == s2[pos]);
            int newState = (newLow << 1) | newHigh;
            ans += dfs(pos + 1, nxtMatched, newState);
            ans %= MOD;
        }
        return dp[pos][matched][state] = ans;
    }
    int findGoodStrings(int N, string S1, string S2, string Evil)
    {
        n = N;
        s1 = S1;
        s2 = S2;
        evil = Evil;
        m = evil.size();
        memset(dp, -1, sizeof(dp));
        buildLPS();
        buildTransition();
        return dfs(0, 0, 3);
    }
};
