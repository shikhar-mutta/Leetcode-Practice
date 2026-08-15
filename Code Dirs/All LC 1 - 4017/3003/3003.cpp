// Link: https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string str;
    int K, n;
    unordered_map<long long, int> memo;

    int dp(int i, int mask, bool used) {
        if (i == n) return 1;
        long long key = ((long long)i << 28) | ((long long)mask << 1) | (used ? 1 : 0);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int bit = 1 << (str[i] - 'a');
        int best = 0;

        // Option 1: don't use the change here
        int newMask = mask | bit;
        if (__builtin_popcount(newMask) <= K) {
            best = max(best, dp(i + 1, newMask, used));
        } else {
            best = max(best, 1 + dp(i + 1, bit, used));
        }

        // Option 2: use the change here (if not used yet) - try every replacement letter
        if (!used) {
            for (int c = 0; c < 26; c++) {
                int cbit = 1 << c;
                if (cbit == bit) continue; // same as original, no-op
                int nm2 = mask | cbit;
                if (__builtin_popcount(nm2) <= K) {
                    best = max(best, dp(i + 1, nm2, true));
                } else {
                    best = max(best, 1 + dp(i + 1, cbit, true));
                }
            }
        }

        memo[key] = best;
        return best;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        str = s;
        K = k;
        n = s.size();
        memo.clear();
        return dp(0, 0, false);
    }
};
