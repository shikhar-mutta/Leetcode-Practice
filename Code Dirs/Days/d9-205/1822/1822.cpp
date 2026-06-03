// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int sign = 1; // Initialize the sign as positive
        for (int num : nums)
        {
            if (num == 0)
            {
                return 0; // If any number is zero, the product is zero
            }
            else if (num < 0)
            {
                sign *= -1; // Flip the sign for negative numbers
            }
        }
        return sign; // Return the final sign of the product
    }
};
