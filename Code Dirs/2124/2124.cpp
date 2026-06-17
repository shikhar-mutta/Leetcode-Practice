// Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool checkString(string s)
    {
        // valid unless a 'b' is ever immediately followed by an 'a'
        return s.find("ba") == string::npos;
    }
};
