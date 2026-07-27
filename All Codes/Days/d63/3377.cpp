// Link: https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V log V) over V = numbers with the same digit count SC: O(V)
//  Approach: Dijkstra over all numbers with the same digit-count as n/m.
//  An edge exists between two numbers differing by +-1 in exactly one
//  digit (no leading zero), and the cost is the SUM of every value n
//  takes throughout the transformation, including the starting value n
//  itself. Prime numbers cannot be visited (including as endpoints).
//  Shortest path from n to m is the answer, -1 if unreachable.
class Solution
{
public:
    int minOperations(int n, int m)
    {
        auto digits = [&](int x)
        {
            int cnt = 0;
            do
            {
                cnt++;
                x /= 10;
            } while (x);
            return cnt;
        };
        int d = digits(n);
        if (d != digits(m))
            return -1;
        int low = 1;
        for (int i = 1; i < d; i++)
            low *= 10;
        int high = low * 10 - 1;
        vector<int> prime(high + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= high; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= high; j += i)
                    prime[j] = 0;
            }
        }
        if (prime[n] || prime[m])
            return -1;
        vector<int> p10 = {1, 10, 100, 1000, 10000};
        vector<long long> dist(high + 1, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        dist[n] = n;
        pq.push({n, n});

        while (!pq.empty())
        {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost != dist[u])
                continue;
            if (u == m)
                return cost;

            for (int i = 0; i < d; i++)
            {
                int dig = (u / p10[i]) % 10;

                if (dig < 9)
                {
                    int v = u + p10[i];

                    if (v <= high && !prime[v])
                    {
                        long long nc = cost + v;
                        if (nc < dist[v])
                        {
                            dist[v] = nc;
                            pq.push({nc, v});
                        }
                    }
                }

                if (dig > 0)
                {
                    int v = u - p10[i];

                    if (v >= low && !prime[v])
                    {
                        long long nc = cost + v;
                        if (nc < dist[v])
                        {
                            dist[v] = nc;
                            pq.push({nc, v});
                        }
                    }
                }
            }
        }
        return -1;
    }
};