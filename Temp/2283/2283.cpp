// Link: https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        int cnt[10] = {0};
        for (char c : num) cnt[c - '0']++;
        for (int i = 0; i < (int)num.size(); i++) {
            if (cnt[i] != num[i] - '0') return false;
        }
        return true;
    }
};
