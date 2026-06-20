// Link: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    bool areOccurrencesEqual(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        int ref = 0; // first nonzero frequency seen; all others must match it
        for (int f : freq)
        {
            if (f == 0)
                continue;
            if (ref == 0)
                ref = f;
            else if (f != ref)
                return false;
        }
        return true;
    }
};
