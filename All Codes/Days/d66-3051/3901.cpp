// Link: https://leetcode.com/problems/good-subsequence-queries/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n+q) log n)  SC: O(n)
// Approach: a good subsequence has length < n and gcd == p; only elements
// divisible by p can appear in it (others act as identity/0 in a gcd
// segment tree, since gcd(x,0)=x). Apply queries as point updates, keeping
// a segment tree of "nums[i] if p|nums[i] else 0" (gcd combine) and a count
// of divisible-by-p positions. After each update, if the root gcd != p, no
// good subsequence; if count < n, using all divisible elements already
// gives length < n; if count == n (every element qualifies, so using all
// of them violates length<n), for n>6 a number-theoretic guarantee makes it
// always still achievable via removing one element, otherwise brute force
// checking each single removal via range gcd queries (n<=6 small).
class Solution
{
public:
    int countGoodSubseq(vector<int> &nums, int p,
                        vector<vector<int>> &queries)
    {
        int n = nums.size(), sz = 1;
        while (sz < n)
            sz <<= 1;
        vector<int> t(2 * sz, 0);
        int m = 0, ans = 0;
        auto val = [&](int x)
        { return x % p == 0 ? x : 0; };
        for (int i = 0; i < n; i++)
            t[sz + i] = val(nums[i]), m += t[sz + i] > 0;
        for (int i = sz - 1; i; i--)
            t[i] = __gcd(t[2 * i], t[2 * i + 1]);
        for (auto &q : queries)
        {
            int i = q[0];
            m -= t[sz + i] > 0;
            nums[i] = q[1];
            t[sz + i] = val(q[1]);
            m += t[sz + i] > 0;
            for (int j = (sz + i) >> 1; j; j >>= 1)
                t[j] = __gcd(t[2 * j], t[2 * j + 1]);
            if (!m || t[1] != p)
                continue;
            if (m < n || n >= 8)
            {
                ans++;
                continue;
            }
            for (int x = 0; x < n; x++)
            {
                int g = 0;
                for (int y = 0; y < n; y++)
                    if (y != x)
                        g = __gcd(g, nums[y]);
                if (g == p)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
