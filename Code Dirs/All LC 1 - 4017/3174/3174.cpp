// Link: https://leetcode.com/problems/clear-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        string res;
        for (char c : s) {
            if (isdigit(c)) {
                if (!res.empty()) res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};
