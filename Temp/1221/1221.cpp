// Link: https://leetcode.com/problems/split-a-string-in-balanced-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0, count = 0;
        for (char c : s) {
            balance += (c == 'R') ? 1 : -1;
            if (balance == 0) count++;
        }
        return count;
    }
};
