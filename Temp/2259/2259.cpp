// Link: https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        string best;
        for (int i = 0; i < (int)number.size(); i++) {
            if (number[i] != digit) continue;
            string candidate = number.substr(0, i) + number.substr(i + 1);
            if (candidate > best) best = candidate;
        }
        return best;
    }
};
