// Link: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: BFS with prime factorization. For each number, we can jump to the next or previous index, or to any index that has a common prime factor with the current number. We can use a sieve to precompute the prime factors of all numbers up to 1e6. We can also use a linked list to keep track of the indices that have the same prime factor. We can use a bitset to keep track of visited indices.
constexpr int M = 1e6 + 1, N = 1e5 + 1;
bitset<M> sieve;
int pIdx[M];
int primes[80000];
int sz = 0;
static void Sieve()
{
    if (sieve[0])
        return;
    sieve[0] = sieve[1] = 1;
    for (int i = 2; i <= 1000; i += 1 + (i > 2))
    {
        if (sieve[i])
            continue;
        primes[sz] = i;
        pIdx[i] = sz++;
        for (int j = i * i; j < M; j += i)
            sieve[j] = 1;
    }
    for (int i = 1001; i < M; i += 2)
    {
        if (!sieve[i])
        {
            primes[sz] = i;
            pIdx[i] = sz++;
        }
    }
}
int mp[80000]; // as heads of linked lists
int nxt[N];
int q[N], front, back;
bool init3629_arrays = []() {
    fill(begin(mp), end(mp), -1);
    fill(begin(nxt), end(nxt), -1);
    return true;
}();
class Solution
{
public:
    static void reset(int n, int maxPidx)
    {
        memset(nxt, -1, sizeof(int) * n);
        memset(mp, -1, sizeof(int) * (maxPidx + 1));
    }
    static int minJumps(vector<int> &nums)
    {
        Sieve();
        //    cout<<sz<<endl;
        const int n = nums.size();

        int maxPidx = -1;
        for (int i = 0; i < n; i++)
        {
            const int x = nums[i];
            if (!sieve[x])
            {
                int idx = pIdx[x];
                nxt[i] = mp[idx];
                mp[idx] = i;
                maxPidx = max(maxPidx, idx);
            }
        }
        bitset<N> vis;
        front = back = 0;
        q[back++] = n - 1;
        vis[n - 1] = 1;
        for (int d = 0; front < back; d++)
        {
            int qz = back - front;
            while (qz--)
            {
                auto i = q[front++];
                if (i == 0)
                {
                    reset(n, maxPidx);
                    return d;
                }
                int x = nums[i];
                if (i > 0 && !vis[i - 1])
                {
                    vis[i - 1] = 1;
                    q[back++] = i - 1;
                }
                if (i < n - 1 && !vis[i + 1])
                {
                    vis[i + 1] = 1;
                    q[back++] = i + 1;
                }

                for (int j = 0; j < sz && x > 1; j++)
                {
                    int p = primes[j];
                    if (!sieve[x])
                        p = x;
                    if (x % p == 0)
                    {
                        const int idx = pIdx[p];
                        while (x % p == 0)
                            x /= p;
                        for (int j = mp[idx]; j != -1; j = nxt[j])
                        {
                            if (!vis[j])
                            {
                                vis[j] = 1;
                                q[back++] = j;
                            }
                        }
                        mp[idx] = -1;
                    }
                }
            }
        }
        return -1;
    }
};
auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();