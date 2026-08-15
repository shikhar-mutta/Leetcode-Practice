// Link: https://leetcode.com/problems/strictly-palindromic-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; base++) {
            vector<int> digits;
            int x = n;
            while (x > 0) {
                digits.push_back(x % base);
                x /= base;
            }
            int lo = 0, hi = digits.size() - 1;
            while (lo < hi) {
                if (digits[lo] != digits[hi]) return false;
                lo++; hi--;
            }
        }
        return true;
    }
};
