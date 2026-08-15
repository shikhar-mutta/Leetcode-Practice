// Link: https://leetcode.com/problems/complex-number-multiplication/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: parse real/imag parts, apply (a+bi)(c+di) = (ac-bd) + (ad+bc)i
class Solution {
    pair<int,int> parse(const string& s) {
        int plusPos = s.find('+');
        int a = stoi(s.substr(0, plusPos));
        int b = stoi(s.substr(plusPos + 1, s.size() - plusPos - 2));
        return {a, b};
    }

public:
    string complexNumberMultiply(string num1, string num2) {
        auto [a, b] = parse(num1);
        auto [c, d] = parse(num2);
        int real = a * c - b * d;
        int imag = a * d + b * c;
        return to_string(real) + "+" + to_string(imag) + "i";
    }
};
