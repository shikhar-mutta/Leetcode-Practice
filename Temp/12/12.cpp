// Link: https://leetcode.com/problems/integer-to-roman/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: greedily subtract the largest value-symbol pair (including subtractive forms like 900="CM") that fits
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> vals = {
            {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
            {50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}
        };
        string res;
        for (auto& [v, sym] : vals) {
            while (num >= v) {
                res += sym;
                num -= v;
            }
        }
        return res;
    }
};
