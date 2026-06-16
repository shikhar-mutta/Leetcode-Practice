// Link: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    bool hasSameDigits(string s)
    {
        for (int n = s.size(); n > 2; --n)                                           // reduce the string by one digit
            for (int i = 1; i < n; s[i - 1] = (s[i - 1] + s[i] - 96) % 10 + 48, ++i) // add the two digits and replace the first digit with the last digit of the sum
                ;
        return s[0] == s[1];
    }
};