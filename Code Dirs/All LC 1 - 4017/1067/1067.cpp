// Link: https://leetcode.com/problems/digit-count-in-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitsCount(int d, int low, int high) {
        return countDigit(d, high) - countDigit(d, low - 1);
    }

private:
    long long countDigit(int d, int n) {
        if (n <= 0) return 0;
        long long count = 0;
        for (long long p = 1; p <= n; p *= 10) {
            long long higher = n / (p * 10);
            long long cur = (n / p) % 10;
            long long lower = n % p;
            if (d > 0) {
                count += higher * p;
                if (cur > d) count += p;
                else if (cur == d) count += lower + 1;
            } else {
                if (higher == 0) continue;
                count += (higher - 1) * p;
                if (cur > 0) count += p;
                else count += lower + 1;
            }
        }
        return count;
    }
};
