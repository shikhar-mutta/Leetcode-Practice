// Link: https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<long long> hits(n);
        for (int i = 0; i < n; i++) hits[i] = (health[i] + power - 1) / power;

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return hits[a] * damage[b] < hits[b] * damage[a];
        });

        long long total = 0, cumHits = 0;
        for (int idx : order) {
            cumHits += hits[idx];
            total += (long long)damage[idx] * cumHits;
        }
        return total;
    }
};
