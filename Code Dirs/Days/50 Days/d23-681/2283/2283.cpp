// Link: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool digitCount(string num)
    {
        int freq[10] = {0};
        for (char c : num)
            freq[c - '0']++; // count occurrences of each digit
        // digit at index i must equal how many times i appears
        for (int i = 0; i < (int)num.size(); i++)
            if (num[i] - '0' != freq[i])
                return false;
        return true;
    }
};
