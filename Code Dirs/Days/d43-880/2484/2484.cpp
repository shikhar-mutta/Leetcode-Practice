// Link: https://leetcode.com/problems/count-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*10*10) = O(n). SC: O(10*10) = O(1)
//  Approach: Count the number of pairs of digits in the prefix and suffix. For each digit in the middle, multiply the number of pairs in the prefix and suffix to get the total number of palindromic subsequences.
class Solution
{
public:
    int countPalindromes(string s)
    {
        const long long MOD = 1e9 + 7;
        int n = s.size();
        long long cntPre[10] = {}, cntSuf[10] = {};
        long long pairPre[10][10] = {}, pairSuf[10][10] = {};

        // pairSuf[x][y] = #(j<k) with s[j]=x, s[k]=y in the suffix
        for (int i = n - 1; i >= 0; i--)
        {
            int d = s[i] - '0';
            for (int y = 0; y < 10; y++)
                pairSuf[d][y] = (pairSuf[d][y] + cntSuf[y]) % MOD;
            cntSuf[d]++;
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int d = s[i] - '0';
            // remove position i from the suffix counts
            cntSuf[d]--;
            for (int y = 0; y < 10; y++)
                pairSuf[d][y] = (pairSuf[d][y] - cntSuf[y] + MOD) % MOD;

            // i is the middle of pattern x y [i] y x
            for (int x = 0; x < 10; x++)
                for (int y = 0; y < 10; y++)
                    ans = (ans + pairPre[x][y] * pairSuf[y][x]) % MOD;

            // add position i to the prefix counts
            for (int x = 0; x < 10; x++)
                pairPre[x][d] = (pairPre[x][d] + cntPre[x]) % MOD;
            cntPre[d]++;
        }
        return (int)ans;
    }
};
