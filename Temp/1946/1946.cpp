// Link: https://leetcode.com/problems/largest-number-after-mutating-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size();
        bool started = false;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            if (change[d] > d) {
                num[i] = '0' + change[d];
                started = true;
            } else if (started) {
                break;
            }
        }
        return num;
    }
};
