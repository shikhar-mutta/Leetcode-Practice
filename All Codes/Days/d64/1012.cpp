// Link: https://leetcode.com/problems/numbers-with-repeated-digits/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(n) * 10)  SC: O(log n)
// Approach: count numbers <= n with ALL DISTINCT digits, then answer =
// n - thatCount. Count numbers with fewer digits than n freely via
// permutation counts (9 * P(9,len-1)), then walk n's own digits: at
// each position, count how many smaller unused digits could be placed
// (times permutations of the remaining positions from unused digits),
// then fix n's actual digit and continue only if it's still unused;
// stop (repeat found) otherwise. If the walk completes, n itself
// (having all distinct digits) is also counted.
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int L = s.size();

        auto perm = [](int avail, int choose) {
            long long r = 1;
            for (int i = 0; i < choose; i++) r *= (avail - i);
            return r;
        };

        long long distinctCount = 0;
        for (int len = 1; len < L; len++) {
            distinctCount += 9 * perm(9, len - 1);
        }

        vector<bool> used(10, false);
        bool ok = true;
        for (int i = 0; i < L; i++) {
            int d = s[i] - '0';
            int startDigit = (i == 0) ? 1 : 0;
            for (int cand = startDigit; cand < d; cand++) {
                if (used[cand]) continue;
                int remainingSlots = L - i - 1;
                int availableDigits = 10 - (i + 1);
                distinctCount += perm(availableDigits, remainingSlots);
            }
            if (used[d]) { ok = false; break; }
            used[d] = true;
        }
        if (ok) distinctCount += 1;

        return (int)(n - distinctCount);
    }
};
