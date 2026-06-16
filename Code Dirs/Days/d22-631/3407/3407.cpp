// Link: https://leetcode.com/problems/substring-matching-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasMatch(string s, string p) {
        // p = left + '*' + right
        int star = p.find('*');
        string left = p.substr(0, star), right = p.substr(star + 1);

        size_t i = s.find(left);                 // left must appear in s
        if (i == string::npos) return false;
        // right must appear at or after the end of that left match
        return s.find(right, i + left.size()) != string::npos;
    }
};
