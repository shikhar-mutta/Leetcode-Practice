// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums)
        {
            // Update the three largest and two smallest values
            if (x > max1) { max3 = max2; max2 = max1; max1 = x; }
            else if (x > max2) { max3 = max2; max2 = x; }
            else if (x > max3) { max3 = x; }

            // Update the two smallest values
            if (x < min1) { min2 = min1; min1 = x; }
            else if (x < min2) { min2 = x; }
        }

        // Example: [-4, -3, -2, 2, 3]
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
