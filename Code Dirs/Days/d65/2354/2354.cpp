// Link: https://leetcode.com/problems/number-of-excellent-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + 30^2), SC: O(30)
// Approach: Count the number of 1s in the binary representation of each number and store the counts in an array. Then, for each pair of counts, check if their sum is greater than or equal to k and calculate the number of excellent pairs accordingly.
class Solution
{
public:
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        const int n = nums.size();
        int cnt[30] = {0};
        for (int i = 0; i < n; ++i)
            ++cnt[__builtin_popcount(nums[i])];
        long long res = 0;
        for (int i = 1; i < 30; ++i)
        {
            for (int j = max(i, k - i); j < 30; ++j)
                res += (i == j ? 1LL : 2LL) * cnt[i] * cnt[j];
        }
        return res;
    }
};