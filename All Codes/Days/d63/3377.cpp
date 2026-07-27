// Link: https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V log V) over V = numbers with the same digit count SC: O(V)
// Approach: Dijkstra over all numbers with the same digit-count as n/m.
// An edge exists between two numbers differing by +-1 in exactly one
// digit (no leading zero), and the cost is the SUM of every value n
// takes throughout the transformation, including the starting value n
// itself. Prime numbers cannot be visited (including as endpoints).
// Shortest path from n to m is the answer, -1 if unreachable.
class Solution {
public:
    int minOperations(int n, int m) {
        auto isPrime = [](int x) {
            if (x < 2) return false;
            for (int i = 2; (long long)i * i <= x; i++) if (x % i == 0) return false;
            return true;
        };

        string sn = to_string(n);
        int digits = sn.size();
        int lo = (digits == 1) ? 0 : (int)pow(10, digits - 1);
        int hi = (int)pow(10, digits) - 1;

        if (isPrime(n) || isPrime(m)) return -1;

        unordered_map<int, long long> dist;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        dist[n] = n;
        pq.push({n, n});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (dist.count(u) && d > dist[u]) continue;
            if (u == m) return (int)d;

            string s = to_string(u);
            for (int i = 0; i < (int)s.size(); i++) {
                for (int delta : {-1, 1}) {
                    int nd = (s[i] - '0') + delta;
                    if (nd < 0 || nd > 9) continue;
                    if (i == 0 && nd == 0 && s.size() > 1) continue;
                    string ns = s;
                    ns[i] = '0' + nd;
                    int v = stoi(ns);
                    if (v < lo || v > hi) continue;
                    if (isPrime(v)) continue;
                    long long nw = d + v;
                    if (!dist.count(v) || nw < dist[v]) {
                        dist[v] = nw;
                        pq.push({nw, v});
                    }
                }
            }
        }
        return dist.count(m) ? (int)dist[m] : -1;
    }
};
