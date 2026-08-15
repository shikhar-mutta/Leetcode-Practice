// Link: https://leetcode.com/problems/minimum-cost-to-equalize-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: We can use binary search to find the minimum cost to equalize the array. We can use a helper function to calculate the cost of equalizing the array to a target value. We can then use binary search to find the minimum cost by checking if the cost of equalizing the array to a target value is less than or equal to the minimum cost found so far. We can also use the fact that the cost of equalizing the array to a target value is a convex function, so we can check a few target values around the maximum value of the array and the balancing point to find the minimum cost.
class Solution
{
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using i128 = __int128_t;

    long long minCostToEqualizeArray(vector<int> &nums, int cost1, int cost2)
    {
        int n = nums.size();
        ll mn = *min_element(nums.begin(), nums.end());
        ll mx = *max_element(nums.begin(), nums.end());
        ll sum = 0;
        for (int x : nums)
            sum += x;

        if (n == 1)
            return 0;

        if (n == 2)
        {
            return ((mx - mn) % MOD * cost1) % MOD;
        }

        if (cost2 >= 2LL * cost1)
        {
            ll need = mx * 1LL * n - sum;
            return (need % MOD) * cost1 % MOD;
        }

        auto getCost = [&](ll T) -> i128
        {
            i128 S = (i128)T * n - sum;
            i128 M = (i128)T - mn;
            i128 pairs = min(S / 2, S - M);
            i128 singles = S - 2 * pairs;
            return pairs * cost2 + singles * cost1;
        };

        i128 ans = getCost(mx);

        // Always check a few targets from mx itself
        for (ll T = mx; T <= mx + 2; T++)
        {
            ans = min(ans, getCost(T));
        }

        // Check around the dominance/balancing boundary
        ll x = sum - 2 * mn;
        ll t0 = (x + (n - 3)) / (n - 2); // ceil((sum - 2*mn)/(n-2))

        for (ll T = max(mx, t0 - 2); T <= t0 + 2; T++)
        {
            ans = min(ans, getCost(T));
        }

        return (long long)(ans % MOD);
    }
};
