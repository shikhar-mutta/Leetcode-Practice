// Link: https://leetcode.com/problems/sum-of-scores-of-built-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: We can use the Z-algorithm to solve this problem. The Z-algorithm calculates the Z-array for a given string, where Z[i] is the length of the longest substring starting from s[i] that is also a prefix of s. The sum of the Z-array gives us the total score of the string. We can calculate the Z-array in linear time and then sum up the values to get the final answer.
class Solution
{
public:
    void zCalculate(string &a, vector<long long> &z)
    {
        int n = a.length();
        int L = 0;
        int R = 0;

        for (int i = 1; i < n; i++)
        {
            if (R < i)
            {
                L = R = i;
                while (R < n && a[R] == a[R - L])
                {
                    R++;
                }
                z[i] = R - L;
                R--;
            }
            else
            {
                int K = i - L;
                if (z[K] < R - i + 1)
                {
                    z[i] = z[K];
                }
                else
                {
                    L = i;
                    while (R < n && a[R] == a[R - L])
                    {
                        R++;
                    }
                    z[i] = R - L;
                    R--;
                }
            }
        }
    }
    long long sumScores(string s)
    {
        int n = s.length();
        vector<long long> z(n, 0);
        z[0] = n;
        zCalculate(s, z);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += z[i];
        }

        return ans;
    }
};
