// Link: https://leetcode.com/problems/number-of-integers-with-popcount-depth-equal-to-k-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int depthOf(long long x) {
        int d = 0;
        while (x != 1) {
            x = __builtin_popcountll(x);
            d++;
        }
        return d;
    }

    long long C[65][65];

    long long countWithPopcount(long long n, int m) {
        if (n < 0) return 0;
        vector<int> bits;
        for (int i = 62; i >= 0; i--) bits.push_back((n >> i) & 1);
        // strip leading zeros (keep at least representation consistent)
        int start = 0;
        while (start < (int)bits.size() - 1 && bits[start] == 0) start++;
        vector<int> b(bits.begin() + start, bits.end());

        int onesSoFar = 0;
        long long result = 0;
        int len = b.size();
        for (int i = 0; i < len; i++) {
            if (b[i] == 1) {
                int remaining = len - i - 1;
                int need = m - onesSoFar;
                if (need >= 0 && need <= remaining) result += C[remaining][need];
                onesSoFar++;
            }
        }
        if (onesSoFar == m) result += 1;
        return result;
    }

    long long popcountDepth(long long n, int k) {
        for (int i = 0; i <= 64; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) C[i][j] = 1;
                else C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }

        if (k == 0) return (n >= 1) ? 1 : 0;

        long long total = 0;
        for (int m = 1; m <= 60; m++) {
            if (depthOf(m) == k - 1) total += countWithPopcount(n, m);
        }
        // x = 1 has depth 0 by definition (base case), not via the recursive relation;
        // it gets miscounted above when k == 1 since popcount(1) = 1 and depth(1) == 0.
        if (k == 1 && n >= 1) total -= 1;
        return total;
    }
};
