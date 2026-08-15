// Link: https://leetcode.com/problems/minimum-total-cost-to-process-all-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: The minimum cost is achieved by processing all elements with the optimal strategy.
class Solution
{
public:
    static const int MOD = 1000000007;
    int minimumCost(vector<int> &nums, int k)
    {
        long long sum = 0;
        for (auto it : nums)
        {
            sum = (sum + it);
        }
        long long val = ((sum - 1) / k) % MOD;

        return (int)((val * (val + 1) / 2) % MOD);
    }
};