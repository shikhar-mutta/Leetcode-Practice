// Link: https://leetcode.com/problems/second-largest-digit-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int secondHighest(string s)
    {
        bool seen[10] = {false};
        for (char c : s)
            if (isdigit((unsigned char)c))
                seen[c - '0'] = true;

        // walk digits high to low; return the second distinct one found
        int found = 0;
        for (int d = 9; d >= 0; d--)
            if (seen[d] && ++found == 2)
                return d;
        return -1;
    }
};
