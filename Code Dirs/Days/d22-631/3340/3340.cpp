// Link: https://leetcode.com/problems/check-balanced-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        // add even-index digits, subtract odd-index digits; balanced iff result is 0
        int diff = 0;
        for (int i = 0; i < (int)num.size(); i++)
            diff += (i % 2 ? -1 : 1) * (num[i] - '0');
        return diff == 0;
    }
};
