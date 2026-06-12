// Link: https://leetcode.com/problems/to-lower-case/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string toLowerCase(string s)
    {
        for (auto &c : s)
            c = tolower(c);
        return s;
    }
};
