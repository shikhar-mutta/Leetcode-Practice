// Link: https://leetcode.com/problems/maximum-segment-sum-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N alpha(N)), SC: O(N)
//  Approach: process queries in reverse (build-up instead of tear-down), DSU union with active left/right neighbors, track running max segment sum.
struct DSU
{
    inline static constexpr int nMx{100001};
    inline static int id[nMx];
    inline static long long sz[nMx];
    int cnt;
    DSU(const int n, vector<int> &nums) : cnt{n}
    {
        iota(id, id + n, 0);
        copy(nums.begin(), nums.end(), sz);
    }
    int fnd(const int i) { return id[i] == i ? i : (id[i] = fnd(id[i])); }
    bool con(const int i, const int j)
    {
        int rI{fnd(i)}, rJ{fnd(j)};
        if (rI != rJ)
        {
            if (sz[rI] > sz[rJ])
            {
                rI ^= rJ;
                rJ ^= rI;
                rI ^= rJ;
            }
            id[rI] = rJ;
            sz[rJ] += sz[rI];
            --cnt;
            return true;
        }
        return false;
    }
};

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums,
                                        vector<int> &removeQueries)
    {
        const int n{static_cast<int>(nums.size())};
        DSU uf{n, nums};
        vector<long long> res(n);
        long long mx{0};
        for (const int j : views::reverse(views::iota(0, n)))
        {
            const int i{removeQueries[j]};
            res[j] = mx;
            if (i < n - 1 && nums[i + 1] == 0)
                uf.con(i, i + 1);
            if (i > 0 && nums[i - 1] == 0)
                uf.con(i, i - 1);
            nums[i] = 0;
            mx = max(mx, uf.sz[uf.fnd(i)]);
        }
        return res;
    }
};
