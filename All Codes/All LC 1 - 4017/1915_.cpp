// Link: https://leetcode.com/problems/number-of-wonderful-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        int mask = 0;            // 10 letters, 0-9
        long long freq[1 << 10]; // 1024 possible masks
        memset(freq, 0, sizeof(freq));
        freq[0] = 1; // empty prefix
        long long ans = 0;
        for (char c : word)
        {
            mask ^= 1 << (c - 'a'); // toggle the bit for the current letter
            ans += freq[mask];      // all letters even
            for (int b = 0; b < 10; ++b)
                ans += freq[mask ^ (1 << b)]; // exactly one odd
            ++freq[mask];                     // update frequency of the current mask
        }
        return ans;
    }
};
