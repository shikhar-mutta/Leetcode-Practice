// Link: https://leetcode.com/problems/maximize-grid-happiness/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n, I, E;
    vector<int> pow3;
    unordered_map<long long, int> memo;

    int neighborDelta(int a, int b) {
        // a, b in {0=empty,1=intro,2=extro}
        if (a == 0 || b == 0) return 0;
        int d = 0;
        if (a == 1) d -= 30; else d += 20;
        if (b == 1) d -= 30; else d += 20;
        return d;
    }

    int dfs(int pos, int mask, int intro, int extro) {
        if (pos == m * n) return 0;
        if (intro == 0 && extro == 0) return 0;
        long long key = ((long long)pos * 729 + mask) * 49 + intro * 7 + extro;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int row = pos / n, col = pos % n;
        int leftType = (col == 0) ? 0 : (mask % 3); // least significant digit = most recently placed = immediate left
        int topType = (row == 0) ? 0 : (mask / pow3[n-1]); // most significant digit = n back = directly above

        int best = INT_MIN;
        // option 0: empty
        {
            int nmask = (mask % pow3[n-1]) * 3 + 0;
            best = max(best, dfs(pos + 1, nmask, intro, extro));
        }
        // option 1: introvert
        if (intro > 0) {
            int val = 120;
            if (col > 0) val += neighborDelta(1, leftType);
            if (row > 0) val += neighborDelta(1, topType);
            int nmask = (mask % pow3[n-1]) * 3 + 1;
            best = max(best, val + dfs(pos + 1, nmask, intro - 1, extro));
        }
        // option 2: extrovert
        if (extro > 0) {
            int val = 40;
            if (col > 0) val += neighborDelta(2, leftType);
            if (row > 0) val += neighborDelta(2, topType);
            int nmask = (mask % pow3[n-1]) * 3 + 2;
            best = max(best, val + dfs(pos + 1, nmask, intro, extro - 1));
        }
        memo[key] = best;
        return best;
    }
public:
    int getMaxGridHappiness(int m_, int n_, int introvertsCount, int extrovertsCount) {
        m = m_; n = n_; I = introvertsCount; E = extrovertsCount;
        pow3.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) pow3[i] = pow3[i-1] * 3;
        return dfs(0, 0, I, E);
    }
};
