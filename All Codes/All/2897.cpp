// Link: https://leetcode.com/problems/apply-operations-on-array-to-maximize-sum-of-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * K), SC: O(1)
// Approach: We can use a frequency array to keep track of the number of elements that have a 1 in each bit position. For each operation, we can construct the largest possible number by checking which bits have a frequency greater than the current operation index. We then square this number and add it to the sum. Finally, we return the sum modulo 1e9 + 7.
class Solution
{
public:
    int maxSum(const vector<int> &nums, int k)
    {
        array<unsigned int, 30> frequency{};
        const int MOD = 1e9 + 7;
        for (const int num : nums)
        {
            for (int j = 0; j < 30; j++)
            {
                frequency[j] += ((num >> j) & 1);
            }
        }
        __int128 sum = 0;
        for (int i = 0; i < k; i++)
        {
            long long candidate = 0;
            for (int j = 0; j < 30; j++)
            {
                candidate |= (static_cast<long long>(frequency[j] > i) << j);
            }
            sum += (candidate * candidate);
        }
        return sum % MOD;
    }
};
