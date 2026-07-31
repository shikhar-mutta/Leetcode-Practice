// Link: https://leetcode.com/problems/minimum-space-wasted-from-packaging/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + mlogm)  SC: O(n)
//  Approach: We first calculate the prefix sum of the package sizes to efficiently compute the total size of packages that can fit into a box. We then iterate through each box size, sort the box sizes, and for each box size, we calculate the total wasted space by subtracting the total size of packages that can fit into the box from the total size of the box. We keep track of the minimum wasted space across all box sizes and return it. If no box can fit all packages, we return -1 indicating that it's not possible to package all items.
class Solution
{
public:
    int minWastedSpace(vector<int> &p, vector<vector<int>> &boxes)
    {
        int mx_p = *max_element(p.begin(), p.end());
        vector<long long> cnt(mx_p + 1);
        long long psum = 0;
        int mod = 1e9 + 7;

        for (int &x : p)
            psum = (psum + x) % mod, cnt[x]++;
        for (int i = 1; i < cnt.size(); i++)
        {
            cnt[i] += cnt[i - 1];
        }

        unsigned long long ans = LONG_MAX;
        for (auto &b : boxes)
        {
            sort(b.begin(), b.end());

            unsigned long long cost = 0;
            int prev_x = 0;
            int used_cnt = 0;
            for (int &x : b)
            {
                long long c = cnt[min(x, mx_p)] - cnt[prev_x];
                used_cnt += c;
                cost += c * x;
                prev_x = min(x, mx_p);
            }
            if (used_cnt == p.size())
                ans = min(ans, cost);
        }

        return ans == LONG_MAX ? -1 : (ans - psum + mod) % mod;
    }
};
