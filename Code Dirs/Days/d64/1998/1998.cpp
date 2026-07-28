// Link: https://leetcode.com/problems/gcd-sort-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O((n + maxVal) * alpha)  SC: O(maxVal)
// Approach: union numbers that share a prime factor (via smallest-prime-factor
// sieve, unioning each number with each of its prime factors in the same DSU
// space). Sort a copy; the array is reachable iff each position's original
// and target values are in the same connected component.
class Solution {
    vector<int> par;
    int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) par[a] = b;
    }
public:
    bool gcdSort(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx + 1, 0);
        for (int i = 2; i <= mx; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= mx; j += i)
                    if (spf[j] == 0) spf[j] = i;
            }
        }
        par.resize(mx + 1);
        iota(par.begin(), par.end(), 0);
        for (int x : nums) {
            int v = x;
            while (v > 1) {
                int p = spf[v];
                unite(x, p);
                while (v % p == 0) v /= p;
            }
        }
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            if (find(nums[i]) != find(sorted[i])) return false;
        }
        return true;
    }
};
