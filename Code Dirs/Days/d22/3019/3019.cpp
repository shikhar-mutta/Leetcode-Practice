// Link: https://leetcode.com/problems/number-of-changing-keys/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countKeyChanges(string s)
    {
        // count adjacent chars that differ when compared case-insensitively
        int changes = 0;
        for (int i = 1; i < (int)s.size(); ++i)
            if (tolower(s[i]) != tolower(s[i - 1]))
                changes++;
        return changes;
    }
};
