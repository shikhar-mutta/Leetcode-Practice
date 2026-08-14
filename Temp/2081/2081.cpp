// Link: https://leetcode.com/problems/sum-of-k-mirror-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindromeBaseK(long long num, int k) {
        vector<int> digits;
        long long x = num;
        while (x > 0) { digits.push_back(x % k); x /= k; }
        int lo = 0, hi = (int)digits.size() - 1;
        while (lo < hi) {
            if (digits[lo] != digits[hi]) return false;
            lo++; hi--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long total = 0;
        int found = 0;
        for (int len = 1; found < n; len++) {
            int half = (len + 1) / 2;
            long long start = (half == 1) ? 1 : (long long)pow(10, half - 1);
            long long end = (long long)pow(10, half) - 1;
            for (long long h = start; h <= end && found < n; h++) {
                string hs = to_string(h);
                string full = hs;
                string rev = hs;
                reverse(rev.begin(), rev.end());
                if (len % 2 == 0) full += rev;
                else full += rev.substr(1);
                long long num = stoll(full);
                if (isPalindromeBaseK(num, k)) {
                    total += num;
                    found++;
                }
            }
        }
        return total;
    }
};
