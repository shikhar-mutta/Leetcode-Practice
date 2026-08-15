// Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int g = __gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, g);
    }
};
