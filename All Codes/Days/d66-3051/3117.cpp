// Link: https://leetcode.com/problems/minimum-sum-of-values-by-dividing-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * log(n))  SC: O(n * m)
//  Approach: dp[i][j] = min sum of values for nums[0..i] with andValues[0..j] as the AND values of the subarrays. Use a sparse table to compute the AND of any subarray in O(1) time. For each dp[i][j], find the range of indices [lb, rb] such that the AND of nums.
#define ll long long
const int N = 1e4 + 4;

class segmentTree
{
public:
    ll t[4 * N], tg;

    segmentTree() { fill(t, t + 4 * N, 1e18); }

    void upd(int v, int l, int r, int idx, ll val)
    {
        if (l == r)
            t[v] = min(t[v], val);
        else
        {
            int m = (l + r) / 2;
            if (idx <= m)
                upd(2 * v, l, m, idx, val);
            else
                upd(2 * v + 1, m + 1, r, idx, val);
            t[v] = min(t[2 * v], t[2 * v + 1]);
        }
    }

    ll qry(int v, int l, int r, int a, int b)
    {
        if (a > b)
            return 1e18;
        else if (a == l && b == r)
            return t[v];
        else
        {
            int m = (l + r) / 2;
            ll L = qry(2 * v, l, m, a, min(m, b));
            ll R = qry(2 * v + 1, m + 1, r, max(m + 1, a), b);
            return min(L, R);
        }
    }
};

class Solution
{
public:
    ll tb[N][18], dp[N][10];
    segmentTree st[10];

    int minimumValueSum(vector<int> &nums, vector<int> &andValues)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size(), m = andValues.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dp[i][j] = 1e18;

        for (int i = 0; i < n; ++i)
            tb[i][0] = nums[i];
        for (int j = 1; (1 << j) <= n; ++j)
            for (int i = 0; i + (1 << j) - 1 < n; ++i)
                tb[i][j] = tb[i][j - 1] & tb[i + (1 << (j - 1))][j - 1];
        auto _qry = [&](int l, int r) -> int
        {
            int k = 31 - __builtin_clz(r - l + 1);
            return tb[l][k] & tb[r - (1 << k) + 1][k];
        };
        for (int i = 0; i < n; ++i)
        {
            if (_qry(0, i) == andValues[0])
            {
                dp[i][0] = nums[i];
                st[0].upd(1, 0, n - 1, i, dp[i][0]);
            }
            for (int j = min(m, i + 1) - 1; j > 0; --j)
            {
                int lb = -1, rb = -1, l = j, r = i;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    int tmp = _qry(m, i);
                    if (tmp == andValues[j])
                    {
                        lb = m;
                        r = m - 1;
                    }
                    else if (tmp < andValues[j])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                l = j, r = i;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    int tmp = _qry(m, i);
                    if (tmp == andValues[j])
                    {
                        rb = m;
                        l = m + 1;
                    }
                    else if (tmp < andValues[j])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                if (lb != -1 && rb != -1)
                {
                    ll prv = st[j - 1].qry(1, 0, n - 1, lb - 1, rb - 1);
                    if (prv < 1e18)
                    {
                        dp[i][j] = prv + nums[i];
                        st[j].upd(1, 0, n - 1, i, dp[i][j]);
                    }
                }
            }
        }
        return dp[n - 1][m - 1] < 1e18 ? dp[n - 1][m - 1] : -1;
    }
};