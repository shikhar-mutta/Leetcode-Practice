// Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMismatch(const string& s, char start) {
        int count = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            char expected = (i % 2 == 0) ? start : (start == '0' ? '1' : '0');
            if (s[i] != expected) count++;
        }
        return count;
    }

    int minSwaps(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        if (abs(ones - zeros) > 1) return -1;

        int best = INT_MAX;
        if (ones == zeros) {
            best = min(countMismatch(s, '0') / 2, countMismatch(s, '1') / 2);
        } else if (ones > zeros) {
            best = countMismatch(s, '1') / 2;
        } else {
            best = countMismatch(s, '0') / 2;
        }
        return best;
    }
};
