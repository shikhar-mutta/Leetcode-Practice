// Link: https://leetcode.com/problems/check-balanced-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBalanced(string num) {
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < (int)num.size(); i++) {
            if (i % 2 == 0) evenSum += num[i] - '0';
            else oddSum += num[i] - '0';
        }
        return evenSum == oddSum;
    }
};
