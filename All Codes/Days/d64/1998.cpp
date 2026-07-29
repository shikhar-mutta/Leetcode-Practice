// Link: https://leetcode.com/problems/gcd-sort-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(nums)))  SC: O(max(nums))
// Approach: Use union-find to group numbers that share a common prime factor. For each number, find its prime factors and union them with the number. After processing all numbers, check if each number can be connected to its sorted position through the union-find structure.
const int N = 1e5 + 5;
bool vis[N];
int par[N];
int pr[N];
int find(int x) { return par[x] = par[x] == x ? x : find(par[x]); }
class Solution
{
public:
    bool gcdSort(const vector<int> &nums)
    {
        int mx = 0;
        for (auto v : nums)
        {
            mx = max(mx, v);
            vis[v] = 1;
        }
        iota(par, par + mx + 1, 0);
        for (int i = 2; i <= mx; i++)
        {
            if (!pr[i])
            {
                int fi = (vis[i] ? i : -1);
                for (int j = i + i; j <= mx; j += i)
                {
                    pr[j] = 1;
                    if (vis[j])
                    {
                        if (fi != -1)
                        {
                            par[find(j)] = find(fi);
                        }
                        else
                            fi = j;
                    }
                }
            }
        }
        vector<int> nums2 = nums;
        ranges::sort(nums2);
        bool ret = 1;
        int n = nums.size();
        for (int i = 0; i < n && ret; i++)
            ret &= find(nums[i]) == find(nums2[i]);
        fill(pr, pr + mx + 1, 0);
        fill(vis, vis + mx + 1, 0);
        return ret;
    }
};