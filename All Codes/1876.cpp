// Link: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countGoodSubstrings(string s)
    {
        int cnt = 0;
        // check every window of 3: all three chars must differ
        for (int i = 0; i + 2 < (int)s.size(); i++)
            if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
                cnt++;
        return cnt;
    }
};
