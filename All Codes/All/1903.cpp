// Link: https://leetcode.com/problems/largest-odd-number-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time: O(n), Space: O(1)
    string largestOddNumber(string num)
    {
        int n = num.size(), i = n - 1;
        while (i >= 0 && (num[i] - '0') % 2 == 0)
            i--;
        return num.substr(0, i + 1); // empty string if i == -1 (no odd digit)
    }
};
