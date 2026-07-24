// Link: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. We initialize two variables, mx and res, to keep track of the maximum value seen so far and the number of times the prefix is aligned, respectively.
    //  2. We iterate through the flips array, updating mx to be the maximum value seen so far. If mx is equal to the current index + 1, it means that all the bits from 1 to mx are set to 1, and we increment res.
    //  3. Finally, we return res, which represents the number of times the prefix is aligned.
    int numTimesAllBlue(vector<int> &flips)
    {
        int mx = 0, res = 0;
        for (int i = 0; i < flips.size(); ++i)
        {
            mx = max(mx, flips[i]);
            if (mx == i + 1)
                ++res;
        }
        return res;
    }
};
