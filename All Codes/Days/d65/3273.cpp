// Link: https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: classic weighted-scheduling greedy. Each enemy needs time[i]=ceil(health[i]/power)
// turns to kill; while alive it deals damage[i] per turn shared with everyone else still alive.
// Order enemies to minimize total damage taken by sorting on damage[i]/time[i] descending
// (kill the highest damage-per-turn-of-effort enemies first) — proven optimal via a standard
// adjacent-swap exchange argument. Sum contributions using a running total of remaining damage.
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<long long> t(n);
        long long totalDamage = 0;
        for (int i = 0; i < n; i++) {
            t[i] = (health[i] + power - 1) / power;
            totalDamage += damage[i];
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return (long long)damage[a] * t[b] > (long long)damage[b] * t[a];
        });

        long long ans = 0;
        long long remaining = totalDamage;
        for (int i : order) {
            ans += remaining * t[i];
            remaining -= damage[i];
        }
        return ans;
    }
};
