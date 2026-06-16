// Link: https://leetcode.com/problems/count-residue-prefixes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int residuePrefixes(string s)
    {
        // a prefix is a "residue" if its distinct-char count == len(prefix) % 3
        bool seen[26] = {false};
        int distinct = 0, count = 0;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (!seen[s[i] - 'a'])
            {
                seen[s[i] - 'a'] = true;
                distinct++;
            }
            if (distinct == (i + 1) % 3)
                count++; // i+1 = current prefix length
        }
        return count;
    }
};
