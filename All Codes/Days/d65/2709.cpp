// Link: https://leetcode.com/problems/greatest-common-divisor-traversal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log m), SC: O(m) where n is the size of nums and m is the maximum number in nums
// Approach: We can use the Sieve of Eratosthenes to find the smallest prime factor (SPF) for each number up to the maximum number in nums. Then, we can use a union-find (disjoint set union) data structure to group numbers that share common prime factors. If all numbers can be connected through their prime factors, then we can traverse all pairs; otherwise, we cannot.
class Solution
{
    vector<int> parent, rnk;

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]]; // 路徑壓縮（halving）
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b)
    {
        a = find(a), b = find(b);
        if (a == b)
            return;
        if (rnk[a] < rnk[b])
            swap(a, b); // 按秩合併
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }

public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true; // 只有一個元素，沒有 pair 要檢查

        int mx = *max_element(nums.begin(), nums.end());
        if (mx == 1)
            return false; // 有 1 且長度 > 1，1 永遠孤立

        vector<int> spf(mx + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; (long long)i * i <= mx; ++i)
            if (spf[i] == i) // i 是質數
                for (int j = i * i; j <= mx; j += i)
                    if (spf[j] == j)
                        spf[j] = i;

        parent.resize(mx + 1);
        rnk.assign(mx + 1, 0);
        iota(parent.begin(), parent.end(), 0);

        int anchor = -1; // 任取一個質因數當基準
        for (int v : nums)
        {
            if (v == 1)
                return false; // 出現 1 → 孤立 → false
            int prev = -1;
            while (v != 1)
            {
                int p = spf[v]; // 取一個質因數
                if (prev != -1)
                    unite(prev, p); // 把同一個數的質因數合併
                else if (anchor == -1)
                    anchor = p;
                prev = p;
                v /= p; // 除掉這個質因數
            }
        }

        for (int v : nums)
            if (find(spf[v]) != find(anchor))
                return false;

        return true;
    }
};