// Link: https://leetcode.com/problems/count-valid-paths-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(NlogN), SC: O(N)
// Approach: We can use a union-find data structure to keep track of the connected components of the tree. We can also use a sieve to find all the prime numbers up to n. Then, we can iterate through all the edges and for each edge, we can check if both endpoints are prime or not. If both endpoints are prime, we can ignore this edge. If one endpoint is prime and the other is not, we can add the non-prime endpoint to the adjacency list of the prime endpoint. If both endpoints are not prime, we can join them in the union-find data structure. Finally, we can iterate through all the prime numbers and for each prime number, we can count the number of valid paths that start from this prime number and end at any of its non-prime neighbors. We can do this by keeping track of the size of each connected component in the union-find data structure and using this information to calculate the number of valid paths.
const int N = 1e5 + 10;
class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> f, cnt;
    vector<int> primes;
    int idx;
    vector<bool> st;

    void get_primes(int n)
    {
        st[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (!st[i])
                primes[idx++] = i;
            for (int j = 0; primes[j] <= n / i; j++)
            {
                st[primes[j] * i] = true;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }

    int find(int x)
    { // O(1)
        if (f[x] != x)
            f[x] = find(f[x]);
        return f[x];
    }

    void join(int a, int b)
    { // O(1)
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            if (cnt[pa] < cnt[pb])
                swap(pa, pb);
            cnt[pa] += cnt[pb];
            f[pb] = pa;
        }
    }

    long long countPaths(int n, vector<vector<int>> &edges)
    {
        adj.resize(n + 10);
        f.resize(n + 10);
        st.resize(n + 10);
        primes.resize(n + 10);
        cnt.resize(n + 10);
        get_primes(n);
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
            cnt[i] = 1;
        }
        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            bool pa = !st[a], pb = !st[b];
            if (pa && pb)
            {
                continue;
            }
            else if (pa && !pb)
            {
                adj[a].push_back(b);
            }
            else if (!pa && pb)
            {
                adj[b].push_back(a);
            }
            else
            {
                join(a, b);
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!st[i])
            {
                int sum = 0;
                for (int v : adj[i])
                {
                    int anc = find(v);
                    ans += (long long)sum * cnt[anc];
                    sum += cnt[anc];
                }
                // {3, 2, 5}, sum = 10
                ans += sum;
            }
        }
        // cout << cnt[find(1)] << " " << cnt[find(4)] << endl;
        return ans;
    }
};
