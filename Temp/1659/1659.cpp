// Link: https://leetcode.com/problems/maximize-grid-happiness/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M, N;
    vector<int> pow3;
    map<tuple<int,int,int,int>, int> memo;

    int adj(int t) {
        if (t == 1) return -30;
        if (t == 2) return 20;
        return 0;
    }

    int dfs(int pos, int mask, int intro, int extro) {
        if (pos == M * N) return 0;
        if (intro == 0 && extro == 0) return 0;
        auto key = make_tuple(pos, mask, intro, extro);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int r = pos / N, c = pos % N;
        int top = mask / pow3[N - 1];
        int left = (c == 0) ? 0 : (mask % 3);

        int best = dfs(pos + 1, (mask % pow3[N - 1]) * 3 + 0, intro, extro);

        if (intro > 0) {
            int val = 120;
            if (left != 0) val += adj(1) + adj(left);
            if (top != 0) val += adj(1) + adj(top);
            int res = val + dfs(pos + 1, (mask % pow3[N - 1]) * 3 + 1, intro - 1, extro);
            best = max(best, res);
        }
        if (extro > 0) {
            int val = 40;
            if (left != 0) val += adj(2) + adj(left);
            if (top != 0) val += adj(2) + adj(top);
            int res = val + dfs(pos + 1, (mask % pow3[N - 1]) * 3 + 2, intro, extro - 1);
            best = max(best, res);
        }

        memo[key] = best;
        return best;
    }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        M = m; N = n;
        pow3.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) pow3[i] = pow3[i-1] * 3;
        memo.clear();
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};
