// Link: https://leetcode.com/problems/find-the-maximum-factor-score-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(max(nums))) SC: O(n)
// Approach: precompute prefix and suffix GCDs and LCMs, then for each
// index i, compute the GCD of the prefix and suffix GCDs (excluding nums[i]) and the LCM of the prefix and suffix LCMs (excluding nums[i]), and take the maximum product of these two values across all indices.
class Solution
{
public:
    using ll = long long;

    ll gcd(ll a, ll b)
    {
        while (b)
        {
            ll t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

    long long maxScore(vector<int> &nums)
    {
        int n = nums.size();

        vector<ll> preGcd(n + 1, 0), sufGcd(n + 1, 0);
        vector<ll> preLcm(n + 1, 1), sufLcm(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            preGcd[i + 1] = gcd(preGcd[i], nums[i]);
            preLcm[i + 1] = lcm(preLcm[i], nums[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            sufGcd[i] = gcd(sufGcd[i + 1], nums[i]);
            sufLcm[i] = lcm(sufLcm[i + 1], nums[i]);
        }

        ll ans = preGcd[n] * preLcm[n];

        for (int i = 0; i < n; i++)
        {
            ll g = gcd(preGcd[i], sufGcd[i + 1]);
            ll l = lcm(preLcm[i], sufLcm[i + 1]);
            ans = max(ans, g * l);
        }

        return ans;
    }
};