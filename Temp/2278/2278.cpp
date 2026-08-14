// Link: https://leetcode.com/problems/percentage-of-letter-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for (char c : s) if (c == letter) count++;
        return count * 100 / (int)s.size();
    }
};
