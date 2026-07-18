// Link: https://leetcode.com/problems/maximum-subarray-with-equal-products/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(1)
    int maxLength(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++)
        { // iterate over all possible starting points of the subarray
            long long prod = 1, lcm = 1, g = 0;
            for (int j = i; j < n; j++)
            { // iterate over all possible ending points of the subarray
                prod *= nums[j];
                lcm = lcm / __gcd(lcm, (long long)nums[j]) * nums[j];
                g = __gcd(g, (long long)nums[j]);
                if (prod == lcm * g)
                    ans = max(ans, j - i + 1);
                else if (prod > lcm * g) // Num are not co-prime
                    break;
            }
        }
        return ans;
    }
};
