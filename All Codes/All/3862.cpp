// Link: https://leetcode.com/problems/find-the-smallest-balanced-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: maintain running sums and products while scanning from right to left.
//  The left sum is the total sum minus the right sum, and the right product is the product of all elements to the right of the current index.
//  If at any index the left sum equals the right product, return that index. If no such index exists, return -1.
class Solution
{
public:
    int smallestBalancedIndex(vector<int> &nums)
    {
        long long leftSum = 0;
        long long rightProduct = 1;

        long long totalSum = 0;
        for (int x : nums)
            totalSum += x;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            totalSum -= nums[i];

            if (totalSum == rightProduct)
                return i;

            // No future product can match if it already exceeds the left sum.
            if (rightProduct > totalSum)
                break;

            // Prevent overflow.
            if (nums[i] != 0 && rightProduct > LLONG_MAX / nums[i])
                break;

            rightProduct *= nums[i];
        }

        return -1;
    }
};