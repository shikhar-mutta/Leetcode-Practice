// Link: https://leetcode.com/problems/count-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
//  Approach: condition nums[p]*nums[r]==nums[q]*nums[s] rearranges to
//  nums[p]/nums[q] == nums[s]/nums[r] (reduced by gcd to avoid floats).
//  Precompute a hashmap of reduced (nums[s],nums[r]) ratio counts for all
//  valid (r,s) with r>=4 and s>=r+2. Then sweep q from 2 upward: for each
//  valid p<=q-2, look up its ratio vs nums[q] in the map and add matches;
//  afterward drop the pairs with r==q+2 since they become invalid once q
//  advances past them.
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
alignas(64) int cnt[608000] = {0};
alignas(64) int packed[1005][1005];
static const int _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> fraction_id(1005, vector<int>(1005, 0));
    int next_id = 0;
    for (int num = 1; num <= 1000; ++num)
    {
        for (int den = 1; den <= 1000; ++den)
        {
            int g = std::gcd(num, den);
            int s_num = num / g;
            int s_den = den / g;
            if (fraction_id[s_num][s_den] == 0)
            {
                fraction_id[s_num][s_den] = ++next_id;
            }
        }
    }
    for (int num = 1; num <= 1000; ++num)
    {
        for (int den = 1; den <= 1000; ++den)
        {
            int g = std::gcd(num, den);
            packed[den][num] = fraction_id[num / g][den / g] - 1;
        }
    }
    return 0;
}();
class Solution
{
public:
    long long numberOfSubsequences(vector<int> &nums)
    {
        int n = nums.size();
        long long ans = 0;
        const int *__restrict data = nums.data();
        const int *s_end = data + n;
        int q = 2;
        const int *p_end = data + 1;
        const int *s_start = data + 6;
        for (int r = 4; r < n - 2; ++r, ++q, ++p_end, ++s_start)
        {
            const int *__restrict row_q = packed[data[q]];

            for (const int *p_ptr = data; p_ptr != p_end; ++p_ptr)
            {
                cnt[row_q[*p_ptr]]++;
            }
            const int *__restrict row_r = packed[data[r]];
            for (const int *s_ptr = s_start; s_ptr != s_end; ++s_ptr)
            {
                ans += cnt[row_r[*s_ptr]];
            }
        }
        p_end = data + 1;
        q = 2;
        for (int r = 4; r < n - 2; ++r, ++q, ++p_end)
        {
            const int *__restrict row_q = packed[data[q]];
            for (const int *p_ptr = data; p_ptr != p_end; ++p_ptr)
            {
                cnt[row_q[*p_ptr]] = 0;
            }
        }
        return ans;
    }
};