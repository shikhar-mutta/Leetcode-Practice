// Link: https://leetcode.com/problems/reverse-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += 2 * k)
            reverse(s.begin() + i, s.begin() + min(i + k, (int)s.size()));

        return s;
    }
};
