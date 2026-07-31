// Link: https://leetcode.com/problems/count-k-subsequences-of-a-string-with-maximum-beauty/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(26 log 26), SC: O(26)
// Approach: only distinct characters matter (26 max). Sort their frequencies descending; the top
// k define max beauty. Characters strictly above the k-th value are forced in (each contributes
// a factor of its frequency, the number of index choices); characters tied at the boundary value
// contribute C(numTied, needed) ways to pick which ones join, each subset contributing
// boundaryFreq^needed (all tied values are equal).
class Solution
{
public:
    const long long MOD = 1e9 + 7;

    int countKSubsequencesWithMaxBeauty(string s, int k)
    {
        vector<long long> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        vector<long long> vals;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0)
                vals.push_back(freq[i]);
        if ((int)vals.size() < k)
            return 0;

        sort(vals.begin(), vals.end(), greater<long long>());
        long long boundary = vals[k - 1];

        long long product = 1;
        int fullyIncluded = 0, numAtBoundary = 0;
        for (int i = 0; i < (int)vals.size(); i++)
        {
            if (vals[i] > boundary)
            {
                product = product * vals[i] % MOD;
                fullyIncluded++;
            }
            else if (vals[i] == boundary)
                numAtBoundary++;
        }
        int needed = k - fullyIncluded;

        // C(numAtBoundary, needed)
        long long comb = 1;
        for (int i = 0; i < needed; i++)
        {
            comb = comb * (numAtBoundary - i) % MOD;
            comb = comb * power(i + 1, MOD - 2) % MOD;
        }

        long long boundaryPow = 1;
        for (int i = 0; i < needed; i++)
            boundaryPow = boundaryPow * boundary % MOD;

        return (int)(product * comb % MOD * boundaryPow % MOD);
    }

    long long power(long long b, long long e)
    {
        long long r = 1;
        b %= MOD;
        while (e > 0)
        {
            if (e & 1)
                r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    }
};
