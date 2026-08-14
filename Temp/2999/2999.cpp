// Link: https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countUpTo(long long x, int limit, const string& s) {
        if (x < 0) return 0;
        string xs = to_string(x);
        int n = xs.size();
        int ls = s.size();
        if (n < ls) return 0;

        long long total = 0;
        // lengths shorter than n: all automatically <= x
        for (int L = ls; L < n; L++) {
            int preLen = L - ls;
            if (preLen == 0) {
                total += 1;
            } else {
                if (limit >= 1) {
                    long long cnt = limit; // first digit 1..limit
                    for (int i = 1; i < preLen; i++) cnt *= (limit + 1);
                    total += cnt;
                }
            }
        }

        // length == n
        int preLen = n - ls;
        if (preLen == 0) {
            if (s.size() == xs.size() && s <= xs) total += 1;
        } else {
            string prefixTarget = xs.substr(0, preLen);
            string suffixTarget = xs.substr(preLen);
            // count prefixes P < prefixTarget
            for (int i = 0; i < preLen; i++) {
                int xi = prefixTarget[i] - '0';
                int lo = (i == 0) ? 1 : 0;
                int hi = min(xi - 1, limit);
                if (hi >= lo) {
                    long long ways = hi - lo + 1;
                    for (int j = i + 1; j < preLen; j++) ways *= (limit + 1);
                    total += ways;
                }
                if (xi > limit) break; // can't match this digit exactly going forward
            }
            // check P == prefixTarget achievable and s <= suffixTarget
            bool achievable = true;
            for (int i = 0; i < preLen; i++) {
                int d = prefixTarget[i] - '0';
                if (d > limit) { achievable = false; break; }
                if (i == 0 && d < 1) { achievable = false; break; }
            }
            if (achievable && s <= suffixTarget) total += 1;
        }
        return total;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return countUpTo(finish, limit, s) - countUpTo(start - 1, limit, s);
    }
};
