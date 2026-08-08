// Link: https://leetcode.com/problems/reformat-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string digits;
        for (char c : number) if (isdigit(c)) digits += c;

        vector<string> groups;
        int i = 0, n = digits.size();
        while (n - i > 4) {
            groups.push_back(digits.substr(i, 3));
            i += 3;
        }
        int rem = n - i;
        if (rem == 4) {
            groups.push_back(digits.substr(i, 2));
            groups.push_back(digits.substr(i + 2, 2));
        } else if (rem > 0) {
            groups.push_back(digits.substr(i, rem));
        }

        string res;
        for (int k = 0; k < (int)groups.size(); k++) {
            if (k) res += "-";
            res += groups[k];
        }
        return res;
    }
};
