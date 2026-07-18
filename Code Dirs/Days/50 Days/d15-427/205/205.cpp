// Link: https://leetcode.com/problems/isomorphic-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isIsomorphic(string s, string t)
    {
        int n = s.size(), m = t.size();
        if (n != m)
            return false;
        unordered_map<char, char> mp, rev;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(s[i]) && mp[s[i]] != t[i])
                return false;
            if (rev.count(t[i]) && rev[t[i]] != s[i])
                return false;
            mp[s[i]] = t[i];
            rev[t[i]] = s[i];
        }
        return true;
    }
};
