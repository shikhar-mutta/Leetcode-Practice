// Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
