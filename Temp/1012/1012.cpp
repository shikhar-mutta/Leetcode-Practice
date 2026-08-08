// Link: https://leetcode.com/problems/numbers-with-repeated-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int len = s.size();

        // Count numbers < n (with fewer digits, or equal digits with all-unique digits) that have all unique digits
        long long uniqueCount = 0;
        // numbers with fewer digits than len
        for (int l = 1; l < len; l++) {
            uniqueCount += 9 * perm(9, l - 1);
        }
        // numbers with exactly len digits, all unique, <= n
        vector<bool> used(10, false);
        for (int i = 0; i < len; i++) {
            int d = s[i] - '0';
            int start = (i == 0) ? 1 : 0;
            for (int digit = start; digit < d; digit++) {
                if (used[digit]) continue;
                uniqueCount += perm(9 - i, len - i - 1);
            }
            if (used[d]) break;
            used[d] = true;
            if (i == len - 1) uniqueCount++;
        }
        return n - (int)uniqueCount;
    }

private:
    long long perm(int n, int k) {
        long long res = 1;
        for (int i = 0; i < k; i++) res *= (n - i);
        return res;
    }
};
