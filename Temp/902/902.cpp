// Link: https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int len = s.size();
        int d = digits.size();
        int count = 0;
        for (int l = 1; l < len; l++) count += pow(d, l);

        for (int i = 0; i < len; i++) {
            bool matched = false;
            for (auto& dig : digits) {
                if (dig[0] < s[i]) {
                    count += pow(d, len - i - 1);
                } else if (dig[0] == s[i]) {
                    matched = true;
                }
            }
            if (!matched) return count;
        }
        return count + 1;
    }

private:
    int pow(int base, int exp) {
        int r = 1;
        for (int i = 0; i < exp; i++) r *= base;
        return r;
    }
};
