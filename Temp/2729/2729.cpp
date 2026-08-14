// Link: https://leetcode.com/problems/check-if-the-number-is-fascinating/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2*n) + to_string(3*n);
        if (s.size() != 9) return false;
        vector<int> count(10, 0);
        for (char c : s) {
            if (c == '0') return false;
            count[c-'0']++;
            if (count[c-'0'] > 1) return false;
        }
        return true;
    }
};
