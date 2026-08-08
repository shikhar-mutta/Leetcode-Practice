// Link: https://leetcode.com/problems/minimum-suffix-flips/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        char cur = '0';
        for (char c : target) {
            if (c != cur) { count++; cur = c; }
        }
        return count;
    }
};
