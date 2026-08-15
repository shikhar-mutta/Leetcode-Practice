// Link: https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxS = s, minS = s;

        char firstNonNine = 0;
        for (char c : s) if (c != '9') { firstNonNine = c; break; }
        if (firstNonNine != 0) {
            for (char &c : maxS) if (c == firstNonNine) c = '9';
        }

        char firstDigit = s[0];
        for (char &c : minS) if (c == firstDigit) c = '0';

        return stoi(maxS) - stoi(minS);
    }
};
