// Link: https://leetcode.com/problems/valid-digit-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: convert n to string, check it contains digit x and doesn't
// start with it.
class Solution
{
public:
    bool validDigit(int n, int x)
    {
        string s = to_string(n);
        char c = '0' + x;
        bool contains = s.find(c) != string::npos;
        bool startsWith = s[0] == c;
        return contains && !startsWith;
    }
};
