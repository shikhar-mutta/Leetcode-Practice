// Link: https://leetcode.com/problems/maximum-balanced-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: "balanced" (nums[j]-nums[i] >= j-i for consecutive picks) means b[i]=nums[i]-i is
// non-decreasing along the subsequence. dp[i] = nums[i] + max(0, best dp[j] for j<i with
// b[j]<=b[i]) — a max-sum non-decreasing subsequence, solved with a Fenwick tree of prefix
// maxima over coordinate-compressed b values.
class Solution
{
public:
    vector<long long> tree;
    int sz;

    void update(int i, long long val)
    {
        for (; i <= sz; i += i & (-i))
            tree[i] = max(tree[i], val);
    }
    long long query(int i)
    {
        long long r = LLONG_MIN;
        for (; i > 0; i -= i & (-i))
            r = max(r, tree[i]);
        return r;
    }

    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> b(n);
        for (int i = 0; i < n; i++)
            b[i] = (long long)nums[i] - i;

        vector<long long> sorted_b = b;
        sort(sorted_b.begin(), sorted_b.end());
        sorted_b.erase(unique(sorted_b.begin(), sorted_b.end()), sorted_b.end());
        sz = sorted_b.size();
        tree.assign(sz + 1, LLONG_MIN);

        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            int rank = lower_bound(sorted_b.begin(), sorted_b.end(), b[i]) - sorted_b.begin() + 1;
            long long best = query(rank);
            long long dpVal = nums[i] + max(0LL, best == LLONG_MIN ? 0LL : best);
            ans = max(ans, dpVal);
            update(rank, dpVal);
        }
        return ans;
    }
};
