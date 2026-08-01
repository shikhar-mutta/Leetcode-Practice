// Link: https://leetcode.com/problems/find-nth-smallest-integer-with-k-one-bits/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(k * log n)  SC: O(1)
// Approach: numbers with exactly k one-bits, ordered ascending by value,
// correspond exactly to the combinadic (combinatorial number system)
// ranking of k-subsets of bit positions. Convert n to a 0-indexed rank and
// greedily pick, from the most significant chosen bit down, the largest
// position c such that C(c,i) <= remaining rank (i = bits left to place),
// subtract C(c,i), and set that bit; repeat for i=k..1.
class Solution {
    long long comb(long long a, long long b) {
        if (b < 0 || a < b) return 0;
        __int128 res = 1;
        for (long long i = 0; i < b; i++) {
            res = res * (a - i) / (i + 1);
            if (res > (__int128)4e18) return (long long)4e18;
        }
        return (long long)res;
    }
public:
    long long nthSmallest(long long n, int k) {
        long long r = n - 1;
        long long ans = 0;
        for (int i = k; i >= 1; i--) {
            long long c = i - 1;
            while (comb(c + 1, i) <= r) c++;
            r -= comb(c, i);
            ans |= (1LL << c);
        }
        return ans;
    }
};
