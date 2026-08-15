// Link: https://leetcode.com/problems/maximize-expression-of-three-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maximizeExpressionOfThree(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, min = INT_MAX;
        for (auto it : nums)
        {
            if (it > max1)
            {
                max2 = max1;
                max1 = it;
            }
            else if (it > max2)
                max2 = it;
            if (it < min)
                min = it;
        }
        return max1 + max2 - min;
    }
};
