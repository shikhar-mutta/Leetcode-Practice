// Link: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        bool hasOneS = s.find('1') != string::npos;
        bool hasOneT = target.find('1') != string::npos;
        return hasOneS == hasOneT;
    }
};
