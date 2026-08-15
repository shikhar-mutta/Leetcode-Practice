// Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<bool> used;
    int n_;

    bool backtrack(int pos) {
        if (pos == (int)res.size()) return true;
        if (res[pos] != 0) return backtrack(pos + 1);
        for (int v = n_; v >= 1; v--) {
            if (used[v]) continue;
            if (v == 1) {
                res[pos] = 1;
                used[1] = true;
                if (backtrack(pos + 1)) return true;
                res[pos] = 0;
                used[1] = false;
            } else {
                int pos2 = pos + v;
                if (pos2 >= (int)res.size() || res[pos2] != 0) continue;
                res[pos] = v; res[pos2] = v;
                used[v] = true;
                if (backtrack(pos + 1)) return true;
                res[pos] = 0; res[pos2] = 0;
                used[v] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        n_ = n;
        res.assign(2 * n - 1, 0);
        used.assign(n + 1, false);
        backtrack(0);
        return res;
    }
};
