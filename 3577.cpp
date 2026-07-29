// Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1e9 + 7;
        int n = complexity.size();

        vector<int> sorted_(complexity.begin(), complexity.end());
        sort(sorted_.begin(), sorted_.end());
        sorted_.erase(unique(sorted_.begin(), sorted_.end()), sorted_.end());
        int m = sorted_.size();

        vector<int> bit(m + 1, 0);
        auto update = [&](int i) {
            for (; i <= m; i += i & (-i)) bit[i]++;
        };
        auto query = [&](int i) {
            int s = 0;
            for (; i > 0; i -= i & (-i)) s += bit[i];
            return s;
        };

        auto rank = [&](int v) {
            return lower_bound(sorted_.begin(), sorted_.end(), v) - sorted_.begin() + 1;
        };

        int r0 = rank(complexity[0]);
        update(r0);

        long long ans = 1;
        for (int i = 1; i < n; i++) {
            int r = rank(complexity[i]);
            int cnt = query(r - 1);
            if (cnt == 0) return 0;
            ans = (ans * cnt) % MOD;
            update(r);
        }

        return (int)ans;
    }
};
