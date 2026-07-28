// Link: https://leetcode.com/problems/largest-palindrome-product/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(10^n) amortized in practice  SC: O(1)
// Approach: for n>=2, build candidate palindromes of 2n digits from
// largest to smallest (by mirroring an n-digit half), then test whether
// each has a factor pair within [10^(n-1), 10^n); the first such
// palindrome found is the answer (mod 1337). n=1 is a special case (9).
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long long upper = 1;
        for (int i = 0; i < n; i++) upper *= 10;
        upper -= 1;
        long long lower = upper / 10 + 1;

        for (long long half = upper; half >= lower; half--) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            long long pal = stoll(s + rev);
            for (long long x = upper; x * x >= pal; x--) {
                if (pal % x == 0) {
                    long long y = pal / x;
                    if (y >= lower && y <= upper) {
                        return (int)(pal % 1337);
                    }
                }
            }
        }
        return -1;
    }
};
