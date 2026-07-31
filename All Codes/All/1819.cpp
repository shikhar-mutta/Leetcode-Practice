// Link: https://leetcode.com/problems/number-of-different-subsequences-gcds/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums)))  SC: O(max(nums))
//  Approach: For each number i from 1 to max(nums), we check if it can be the GCD of some subsequence of nums. We do this by checking all multiples of i and calculating their GCD. If the GCD equals i, we increment our result counter. We use a bitset to keep track of the numbers present in nums for efficient checking.
class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        bitset<200001> seen;
        const int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; ++i)
        {
            seen.set(nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int res = 0;
        for (int i = 1; i <= maxi; ++i)
        {
            int gcdVal = 0;
            for (int j = i; j <= maxi; j += i)
            {
                if (!seen.test(j))
                    continue;
                gcdVal = __gcd(gcdVal, j);
                if (gcdVal == i)
                {
                    ++res;
                    break;
                }
            }
        }
        return res;
    }
};