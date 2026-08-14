// Link: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> evens, odds;
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) evens.push_back(d);
            else odds.push_back(d);
        }
        sort(evens.rbegin(), evens.rend());
        sort(odds.rbegin(), odds.rend());
        int ei = 0, oi = 0;
        string res;
        for (char c : s) {
            int d = c - '0';
            if (d % 2 == 0) res += ('0' + evens[ei++]);
            else res += ('0' + odds[oi++]);
        }
        return stoi(res);
    }
};
