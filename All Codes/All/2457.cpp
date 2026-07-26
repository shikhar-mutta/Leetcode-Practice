// Link: https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(d^2) where d = number of digits in n (each of the ~d rounding
//     steps recomputes the digit sum in O(d))
// SC: O(1)
// Approach: while n's digit sum exceeds target, round n up to the next
// multiple of the next higher power of 10 (this zeroes out the current
// lowest nonzero digit region, which can only shrink the digit sum), and
// keep widening the rounding place until the digit sum condition holds.
// The answer is the total amount added.
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long original = n;
        long long place = 1;

        while (digitSum(n) > target) {
            // round n up to the next multiple of (place * 10),
            // zeroing out the current lowest nonzero digit region
            n = n / (place * 10) * (place * 10) + (place * 10);
            place *= 10;
        }
        return n - original;
    }
private:
    int digitSum(long long x) {
        int s = 0;
        while (x) { s += x % 10; x /= 10; }
        return s;
    }
};
