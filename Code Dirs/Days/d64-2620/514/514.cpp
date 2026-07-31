// Link: https://leetcode.com/problems/freedom-trail/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m)  SC: O(n * m)
//  Approach: dp[cur][kcur] = min steps to spell key[kcur:] starting
//  with ring[cur] at 12:00. For each dp[cur][kcur], find the closest index of key[kcur] in ring to the right and left, and recurse.
//  The answer is dp[0][0] + key.size() (for the button presses).
//  Note: the ring is circular, so we wrap around when searching for the closest index.
class Solution
{
public:
    int dp[102][102];
    int ring(int cur, int kcur, string &s, string &key)
    {
        if (kcur == key.size())
            return 0;
        if (dp[cur][kcur] != -1)
            return dp[cur][kcur];

        int rightpath = 0;
        int leftpath = 0;
        int idxr = cur, idxl = cur;

        while (1)
        {
            if (idxr == s.size())
                idxr = 0;
            if (s[idxr] == key[kcur])
            {
                rightpath++;
                break;
            }
            idxr++;
            rightpath++;
        }
        while (1)
        {
            if (idxl == -1)
                idxl = s.size() - 1;
            if (s[idxl] == key[kcur])
            {
                leftpath++;
                break;
            }
            idxl--;
            leftpath++;
        }
        return dp[cur][kcur] = min(rightpath + ring(idxr, kcur + 1, s, key),
                                   leftpath + ring(idxl, kcur + 1, s, key));
    }
    int findRotateSteps(string s, string key)
    {
        memset(dp, -1, sizeof dp);
        return ring(0, 0, s, key);
    }
};