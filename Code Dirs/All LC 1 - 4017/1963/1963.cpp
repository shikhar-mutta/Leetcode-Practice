// Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, maxDeficit = 0;
        for (char c : s) {
            if (c == '[') balance++;
            else balance--;
            maxDeficit = min(maxDeficit, balance);
        }
        return (-maxDeficit + 1) / 2;
    }
};
