// Link: https://leetcode.com/problems/count-the-number-of-special-characters-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> hasLower(26, false), hasUpper(26, false);
        for (char c : word) {
            if (islower(c)) hasLower[c - 'a'] = true;
            else hasUpper[c - 'A'] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) if (hasLower[i] && hasUpper[i]) cnt++;
        return cnt;
    }
};
