// Link: https://leetcode.com/problems/maximum-matrix-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) where n is the number of rows and m is the number of columns in the matrix
// SC: O(1) constant space
// Approach:
//   1. We will iterate through the matrix and calculate the sum of absolute values of all elements, count the number of negative elements, and find the minimum absolute value in the matrix.
//   2. If the count of negative elements is even, we can make all elements positive and return the sum of absolute values.
//   3. If the count of negative elements is odd, we can make all but one element positive, and the maximum sum will be the sum of absolute values minus twice the minimum absolute value (to account for the one negative element that remains).
class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long absSum = 0;
        int negCount = 0, minAbs = INT_MAX;
        for (auto &row : matrix)
        {
            for (int x : row)
            {
                absSum += abs(x);
                if (x < 0)
                    ++negCount;
                minAbs = min(minAbs, abs(x));
            }
        }
        if (negCount % 2 == 0)
            return absSum;
        return absSum - 2LL * minAbs;
    }
};
