// Link: https://leetcode.com/problems/digit-operations-to-make-two-integers-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; (long long)i * i <= x; i++) if (x % i == 0) return false;
        return true;
    }

    int minOperations(int n, int m) {
        if (isPrime(n) || isPrime(m)) return -1;

        int digits = to_string(n).size();
        int maxVal = 1;
        for (int i = 0; i < digits; i++) maxVal *= 10;
        maxVal -= 1;

        vector<long long> dist(maxVal + 1, LLONG_MAX);
        dist[n] = n;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({n, n});

        while (!pq.empty()) {
            auto [d, v] = pq.top(); pq.pop();
            if (d > dist[v]) continue;
            if (v == m) break;

            int pw = 1;
            for (int p = 0; p < digits; p++) {
                int digit = (v / pw) % 10;
                if (digit < 9) {
                    int nv = v + pw;
                    if (!isPrime(nv)) {
                        long long nd = d + nv;
                        if (nd < dist[nv]) { dist[nv] = nd; pq.push({nd, nv}); }
                    }
                }
                if (digit > 0) {
                    int nv = v - pw;
                    if (!isPrime(nv)) {
                        long long nd = d + nv;
                        if (nd < dist[nv]) { dist[nv] = nd; pq.push({nd, nv}); }
                    }
                }
                pw *= 10;
            }
        }

        return dist[m] == LLONG_MAX ? -1 : (int)dist[m];
    }
};
