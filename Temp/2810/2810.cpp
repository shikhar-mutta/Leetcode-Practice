// Link: https://leetcode.com/problems/faulty-keyboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string finalString(string s) {
        string res;
        for (char c : s) {
            if (c == 'i') reverse(res.begin(), res.end());
            else res.push_back(c);
        }
        return res;
    }
};
