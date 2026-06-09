// Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    int minimumSum(int num)
    {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int num1 = (s[0] - '0') * 10 + (s[2] - '0');
        int num2 = (s[1] - '0') * 10 + (s[3] - '0');
        return num1 + num2;
    }
};
