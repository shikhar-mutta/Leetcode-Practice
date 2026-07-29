// Link: https://leetcode.com/problems/minimum-time-to-transport-all-individuals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        int fullMask = (1 << n) - 1;
        int numStates = (1 << n) * m;
        vector<double> dist(numStates, 1e18);
        auto encode = [&](int mask, int stage) { return mask * m + stage; };

        dist[encode(fullMask, 0)] = 0;
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> pq;
        pq.push({0.0, encode(fullMask, 0)});

        double answer = -1;
        bool found = false;

        while (!pq.empty()) {
            auto [d, state] = pq.top(); pq.pop();
            if (d > dist[state] + 1e-12) continue;
            int mask = state / m, stage = state % m;

            // enumerate non-empty submasks S of mask with popcount <= k
            for (int S = mask; S > 0; S = (S - 1) & mask) {
                int pc = __builtin_popcount(S);
                if (pc > k) continue;
                double maxT = 0;
                for (int i = 0; i < n; i++) if (S & (1 << i)) maxT = max(maxT, (double)time[i]);
                double cost1 = maxT * mul[stage];
                int newMask = mask ^ S;
                int newStage = (stage + (int)floor(cost1)) % m;

                if (newMask == 0) {
                    double cand = d + cost1;
                    if (!found || cand < answer) { answer = cand; found = true; }
                } else {
                    int atDest = (~newMask) & fullMask;
                    for (int r = 0; r < n; r++) {
                        if (!(atDest & (1 << r))) continue;
                        double cost2 = time[r] * mul[newStage];
                        int newMask2 = newMask | (1 << r);
                        int newStage2 = (newStage + (int)floor(cost2)) % m;
                        double nd = d + cost1 + cost2;
                        int state2 = encode(newMask2, newStage2);
                        if (nd < dist[state2]) {
                            dist[state2] = nd;
                            pq.push({nd, state2});
                        }
                    }
                }
            }
        }

        return found ? answer : -1.0;
    }
};
