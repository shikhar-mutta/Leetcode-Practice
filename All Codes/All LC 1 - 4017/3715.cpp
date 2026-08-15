// Link: https://leetcode.com/problems/sum-of-perfect-square-ancestors/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n * sqrt(max(nums))) where n is the number of nodes in the tree and max(nums) is the maximum value in the nums array.
//SC: O(n + sqrt(max(nums))) where n is the number of nodes in the tree and max(nums) is the maximum value in the nums array.
//Approach:
//1. We can use a depth-first search (DFS) approach to traverse the tree and calculate the sum of perfect square ancestors for each node.
//2. We can use a vector to store the count of perfect square ancestors for each node.
//3. We can use a map to store the count of perfect square ancestors for each node.
//4. We can use a recursive function to traverse the tree and calculate the sum of perfect square ancestors for each node.
//5. We can use a helper function to check if a number is a perfect square or not.
//6. We can use a vector to store the perfect square numbers up to the maximum value in the nums array.
int primes[100];
int st[100001], idx[200000], cnts[100000];
vector<int> nums;

int nprimes = []
{
    char sv[316];
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nprimes = 0;
    for (int i = 2; i < 316; ++i)
        if (!sv[i])
        {
            primes[nprimes++] = i;
            for (int j = i * i; j < 316; j += i)
                sv[j] = 1;
        }
    return nprimes;
}();

long long dfs(int n, int p)
{
    int v = 1, u = nums[n];
    for (int i = 0; u != 1 && i < nprimes; ++i)
    {
        if (int p = primes[i]; u % p == 0)
        {
            int p2 = p * p;
            while (u % p2 == 0)
                u /= p2;
            if (u % p == 0)
                u /= p, v *= p;
        }
    }
    v *= u;
    long long res = cnts[v]++;
    for (int i = st[n], e = st[n + 1]; i != e; ++i)
        if (int c = idx[i]; c != p)
            res += dfs(c, n);
    --cnts[v];
    return res;
}

class Solution
{
public:
    long long sumOfAncestors(int n, vector<vector<int>> &edges,
                             vector<int> &nums)
    {
        fill(st, st + n, 0);
        for (const auto &e : edges)
            ++st[e[0]], ++st[e[1]];
        for (int i = 1; i < n; ++i)
            st[i] += st[i - 1];
        st[n] = st[n - 1];
        for (const auto &e : edges)
        {
            int a = e[0], b = e[1];
            idx[--st[a]] = b;
            idx[--st[b]] = a;
        }
        ::nums = move(nums);
        return dfs(0, -1);
    }
};
