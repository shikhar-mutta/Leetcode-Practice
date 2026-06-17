// Link: https://leetcode.com/problems/first-letter-to-appear-twice/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    char repeatedCharacter(string s)
    {
        bool seen[26] = {false};
        // return the first char whose second occurrence we hit
        for (char c : s)
        {
            if (seen[c - 'a'])
                return c;
            seen[c - 'a'] = true;
        }
        return 0; // unreachable per constraints
    }
};
