// Link: https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(finish)), SC: O(1)
// Approach: answer = f(finish) - f(start-1), f(X) counts powerful integers <= X. A powerful
// integer of total length L has a free prefix of length L-len(s) (digits in [0,limit], nonzero
// leading) followed by exactly s. For L less than len(X)'s digit count, every such prefix is
// automatically <= X; for L equal to it, compare digit-by-digit against X's own prefix, handling
// the tied-prefix boundary case by comparing s to X's trailing digits directly.
class Solution {
public:
    long long power(long long b, long long e) {
        long long r = 1;
        while (e > 0) { if (e & 1) r *= b; b *= b; e >>= 1; }
        return r;
    }

    long long countLessOrEqualPrefix(const string& Xprefix, int limit, const string& s, const string& Xsuffix) {
        int prefixLen = Xprefix.size();
        if (prefixLen == 0) return s <= Xsuffix ? 1 : 0;

        long long count = 0;
        bool tight = true;
        for (int i = 0; i < prefixLen; i++) {
            int digitLimit = Xprefix[i] - '0';
            int lo = (i == 0) ? 1 : 0;
            int hi = limit;
            int less = max(0, min(hi, digitLimit - 1) - lo + 1);
            if (less > 0) {
                long long remaining = prefixLen - i - 1;
                count += (long long)less * power(limit + 1, remaining);
            }
            if (digitLimit < lo || digitLimit > hi) { tight = false; break; }
        }
        if (tight && s <= Xsuffix) count++;
        return count;
    }

    long long f(long long X, int limit, const string& s) {
        if (X <= 0) return 0;
        string Xstr = to_string(X);
        int lenX = Xstr.size(), lenS = s.size();
        if (lenX < lenS) return 0;

        long long total = 0;
        for (int L = lenS; L < lenX; L++) {
            int prefixLen = L - lenS;
            total += (prefixLen == 0) ? 1 : (long long)limit * power(limit + 1, prefixLen - 1);
        }

        int prefixLen = lenX - lenS;
        string Xprefix = Xstr.substr(0, prefixLen);
        string Xsuffix = Xstr.substr(prefixLen);
        total += countLessOrEqualPrefix(Xprefix, limit, s, Xsuffix);
        return total;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        for (char c : s) if (c - '0' > limit) return 0;
        return f(finish, limit, s) - f(start - 1, limit, s);
    }
};
