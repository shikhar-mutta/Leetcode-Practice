// Link: https://leetcode.com/problems/largest-palindrome-product/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^n) worst case  SC: O(1)
// Approach: construct candidate palindromes descending from the max
// possible half-length, check if each has a factor pair within the
// n-digit range
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long long upper = 1;
        for (int i = 0; i < n; i++) upper *= 10;
        upper--;
        long long lower = upper / 10 + 1;

        for (long long half = upper; half >= lower; half--) {
            string s = to_string(half);
            string rev = s;
            reverse(rev.begin(), rev.end());
            long long pal = stoll(s + rev);

            for (long long f = upper; f * f >= pal; f--) {
                if (pal % f == 0) {
                    long long other = pal / f;
                    if (other <= upper && other >= lower) return (int)(pal % 1337);
                }
            }
        }
        return -1;
    }
};
