// Link: https://leetcode.com/problems/maximum-of-absolute-value-expression/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input arrays arr1 and arr2
    // SC: O(1) as we are using constant space
    // Approach:
    //  1. We can use the fact that the maximum absolute value expression can be expressed as the maximum of four different expressions:
    //     a. arr1[i] + arr2[i] + i
    //     b. arr1[i] - arr2[i] + i
    //     c. -arr1[i] + arr2[i] + i
    //     d. -arr1[i] - arr2[i] + i
    //  2. We can iterate through the input arrays and calculate the maximum and minimum values for each of the four expressions.
    //  3. The maximum absolute value expression will be the maximum difference between the maximum and minimum values for each of the four expressions.
    //  4. Finally, we return the maximum absolute value expression.
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int signs[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int result = 0;
        for (auto &s : signs)
        {
            int mx = INT_MIN, mn = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int val = s[0] * arr1[i] + s[1] * arr2[i] + i;
                mx = max(mx, val);
                mn = min(mn, val);
            }
            result = max(result, mx - mn);
        }
        return result;
    }
};
