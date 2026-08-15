// Link: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int K;
    string digits;
    map<tuple<int,int,int,int,int>, long long> memo;

    long long solve(int pos, int diff, int rem, int tight, int started) {
        if (pos == (int)digits.size()) {
            return (started && diff == 0 && rem == 0) ? 1 : 0;
        }
        auto key = make_tuple(pos, diff, rem, tight, started);
        if (!tight) {
            auto it = memo.find(key);
            if (it != memo.end()) return it->second;
        }
        int limit = tight ? (digits[pos] - '0') : 9;
        long long total = 0;
        for (int d = 0; d <= limit; d++) {
            int nstarted = started || (d != 0);
            int ndiff = diff;
            int nrem = rem;
            if (nstarted) {
                ndiff += (d % 2 == 0) ? 1 : -1;
                nrem = (rem * 10 + d) % K;
            }
            total += solve(pos + 1, ndiff, nrem, tight && (d == limit), nstarted);
        }
        if (!tight) memo[key] = total;
        return total;
    }

    long long countUpTo(long long n) {
        if (n < 0) return 0;
        digits = to_string(n);
        memo.clear();
        return solve(0, 0, 0, 1, 0);
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        K = k;
        return (int)(countUpTo(high) - countUpTo(low - 1));
    }
};
