// Link: https://leetcode.com/problems/reverse-string-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string reversePrefix(string s, int k)
    {
        // reverse the first k characters in place
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};
