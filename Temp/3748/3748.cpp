// Link: https://leetcode.com/problems/count-stable-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q)  SC: O(n)
// Approach: a subarray is stable iff it's non-decreasing. Precompute
// right[i] = the farthest index the non-decreasing run starting at i
// reaches, and prefix[i+1] = running sum of (length of the non-decreasing
// run ending at i). For query [l,r], let m = min(right[l], r): every
// subarray inside [l,m] (one run) is stable, contributing the triangular
// number count(m-l+1); every later index in (m,r] contributes its own
// run-length (since those runs start after m, safely inside [l,r]), summed
// via prefix[r+1]-prefix[m+1].
class Solution
{
public:
    vector<long long> countStableSubarrays(vector<int> &nums,
                                           vector<vector<int>> &queries)
    {
        int n = nums.size();

        vector<long long> cnt(n);
        vector<int> nxt(n);

        int prv = 0;
        cnt[0] = 1;

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
                prv = i;
            cnt[i] = cnt[i - 1] + 1ll * (i - prv + 1);
        }

        nxt[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i + 1] >= nums[i])
                nxt[i] = nxt[i + 1];
            else
                nxt[i] = i;
        }

        n = queries.size();
        vector<long long> ans(n);

        for (int i = 0; i < n; ++i)
        {
            int l = queries[i][0], r = queries[i][1];

            if (nxt[l] >= r)
                ans[i] = (1ll * (r - l + 1) * (r - l + 2) / 2);
            else
                ans[i] = 1ll * (nxt[l] - l + 1) * (nxt[l] - l + 2) / 2 +
                         cnt[r] - cnt[nxt[l]];
        }

        return ans;
    }
};
