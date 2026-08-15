// Link: https://leetcode.com/problems/maximum-subarray-xor-with-bounded-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*32)  SC: O(n*32)
//  Approach: for each bit from MSB to LSB, try to set it in the answer. For each bit, we can check if there exists a prefix xor that can be combined with the current prefix xor to set that bit in the answer. We can use a sliding window to maintain the valid prefix xors that are within the range of k. We can use a hash map to store the prefix xors and their positions. If we can find a prefix xor that can be combined with the current prefix xor to set the bit, we can update the answer and move on to the next bit. Otherwise, we can move on to the next bit without updating the answer. We can repeat this process for all bits from MSB to LSB and return the final answer.
int pos[1 << 15], lp[40000];
int mn[40000], mx[40000];
int speedup = []
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

void init_lp(const vector<int> &nums, int k)
{
    int mnl = 0, mnr = 0, mxl = 0, mxr = 0, l = -1, N = size(nums);
    for (int i = 0; i < N; ++i)
    {
        int v = nums[i];
        while (mnr > mnl && v <= nums[mn[mnr - 1]])
            --mnr;
        mn[mnr++] = i;
        while (mxr > mxl && v >= nums[mx[mxr - 1]])
            --mxr;
        mx[mxr++] = i;
        if (mnr == mnl + 1)
        {
            int lo = nums[mn[mnl]];
            while (nums[mx[mxl]] - lo > k)
                l = mx[mxl++];
        }
        else if (mxr == mxl + 1)
        {
            int hi = nums[mx[mxl]];
            while (hi - nums[mn[mnl]] > k)
                l = mn[mnl++];
        }
        lp[i] = l;
    }
}

int check(const vector<int> &nums, int tgt, int d, int st)
{
    int cur = 0;
    pos[0] = 0;
    for (int i = 0; i < st; ++i)
        pos[cur ^= (nums[i] >> d)] = i + 1;
    for (int i = st, N = size(nums); i < N; ++i)
    {
        pos[cur ^= (nums[i] >> d)] = i + 1;
        if (pos[cur ^ tgt] > lp[i])
            return i;
    }
    return -1;
}

class Solution
{
public:
    int maxXor(vector<int> &nums, int k)
    {
        init_lp(nums, k);
        int res = *max_element(begin(nums), end(nums));
        if (res <= 1)
            return res;

        int sz = 32 - __builtin_clz(res);
        for (int d = sz - 2, p = 0, r; d >= 0; --d)
            if (!((r = res >> d) & 1))
            {
                fill(pos, pos + (1 << (sz - d)), -1);
                int x = check(nums, r | 1, d, p);
                if (x >= 0)
                {
                    int u = 1 << d;
                    res = (res | u) & ~(u - 1);
                    p = x;
                }
            }
        return res;
    }
};
