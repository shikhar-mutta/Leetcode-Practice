// Link: https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> diff(n + 1, 0);
        for (auto& b : boosts) {
            int l = b[0], r = b[1], v = b[2];
            diff[l] += v;
            diff[r + 1] -= v;
        }
        vector<long long> bonus(n);
        long long run = 0;
        for (int i = 0; i < n; i++) {
            run += diff[i];
            bonus[i] = run;
        }

        auto feasible = [&](long long S) -> bool {
            long long cur = S;
            for (int i = 0; i < n; i++) {
                if (cur + bonus[i] < monsters[i]) return false;
                cur = max(0LL, cur - monsters[i]);
            }
            return true;
        };

        long long lo = 0, hi = 0;
        for (int m : monsters) hi += m;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (feasible(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
