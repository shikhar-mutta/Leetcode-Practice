// Link: https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * maxSum) where m is the number of rows, n is the number of columns, and maxSum is the maximum possible sum of chosen elements
// SC: O(maxSum) where maxSum is the maximum possible sum of chosen elements
// Approach:
//  1. We will use a bitset to keep track of the possible sums we can achieve by choosing one element from each row of the matrix.
//  2. We will iterate through each row of the matrix and for each element in the row, we will update the bitset to include the new possible sums we can achieve by adding that element to the existing sums in the bitset.
//  3. After processing all rows, we will iterate through the bitset to find the minimum absolute difference between the target and the possible sums we can achieve.
class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        const int m = mat.size();
        const int n = mat[0].size();
        bitset<801> b{};
        b.set(0);
        int minsum{0};
        for (const auto &row : mat)
        {
            bitset<801> temp{};
            int minimum{70};
            for (const auto &m : row)
            {
                temp |= b << m;
                minimum = min(minimum, m);
            }
            minsum += minimum;
            swap(b, temp);
        }
        if (minsum >= target)
        {
            return minsum - target;
        }
        int ans{800};
        for (int i{1}; i < 801; ++i)
        {
            ans = (b.test(i)) ? min(ans, abs(target - i)) : ans;
        }
        return ans;
    }
};
