// Link: https://leetcode.com/problems/maximum-value-after-insertion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        bool neg = n[0] == '-';
        char digit = '0' + x;
        int i = neg ? 1 : 0;
        int n_len = n.size();
        while (i < n_len) {
            if (neg ? (n[i] > digit) : (n[i] < digit)) break;
            i++;
        }
        return n.substr(0, i) + digit + n.substr(i);
    }
};
