// Link: https://leetcode.com/problems/beautiful-arrangement/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k) where k = valid arrangements (pruned backtracking)  SC: O(n)
// Approach: backtrack filling positions 1..n, at each position try unused
// numbers satisfying the divisibility condition
class Solution {
    int n, count = 0;
    vector<bool> used;

    void backtrack(int pos) {
        if (pos > n) { count++; return; }
        for (int num = 1; num <= n; num++) {
            if (used[num]) continue;
            if (num % pos != 0 && pos % num != 0) continue;
            used[num] = true;
            backtrack(pos + 1);
            used[num] = false;
        }
    }

public:
    int countArrangement(int n) {
        this->n = n;
        used.assign(n + 1, false);
        backtrack(1);
        return count;
    }
};
