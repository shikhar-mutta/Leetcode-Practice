// Link: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    int beautySum(string s)
    {
        int freq[26] = {0};
        auto givDif = [&]()
        {
            int lw = INT_MAX, hi = INT_MIN;
            for (auto fq : freq)
            {
                if (fq == 0)
                    continue; // only consider chars in substring
                if (fq > hi)
                    hi = fq;
                if (fq < lw)
                    lw = fq;
            }
            return hi - lw;
        };
        int n = s.size(), i, j, sum = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                sum += givDif();
            }
            memset(freq, 0, sizeof(freq));
        }
        return sum;
    }
};
