// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the size of nums.
// SC: O(1) as we are using constant space.
//  Approach:
//   1. We will find the median of the array nums.
//   2. We will find the closest palindrome numbers to the median, one smaller and one larger.
//   3. We will calculate the cost to make all elements equal to the smaller palindrome and the cost to make all elements equal to the larger palindrome.
//   4. We will return the minimum of the two costs.
class Solution
{
private:
    static inline bool isPal(int x)
    {
        int rev = 0, orig = x;
        while (x)
        {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev == orig;
    }
    static inline int nextPal(int x)
    {
        for (int i = x; i < 1000000000; ++i)
        {
            if (isPal(i))
                return i;
        }
        return 999999999;
    }
    static inline int prevPal(int x)
    {
        for (int i = x; i; --i)
        {
            if (isPal(i))
                return i;
        }
        return 1;
    }

public:
    long long minimumCost(vector<int> &nums)
    {
        const int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];
        int lower = prevPal(median);
        int upper = nextPal(median);
        long long costLower = 0, costUpper = 0;
        for (int i = 0; i < n; ++i)
        {
            costLower += abs(nums[i] - lower);
            costUpper += abs(nums[i] - upper);
        }
        return min(costLower, costUpper);
    }
};