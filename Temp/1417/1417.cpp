// Link: https://leetcode.com/problems/reformat-the-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformat(string s) {
        string digits, letters;
        for (char c : s) {
            if (isdigit(c)) digits += c;
            else letters += c;
        }
        if (abs((int)digits.size() - (int)letters.size()) > 1) return "";

        string& longer = digits.size() >= letters.size() ? digits : letters;
        string& shorter = digits.size() >= letters.size() ? letters : digits;

        string res;
        for (int i = 0; i < (int)shorter.size(); i++) {
            res += longer[i];
            res += shorter[i];
        }
        if (longer.size() > shorter.size()) res += longer.back();
        return res;
    }
};
