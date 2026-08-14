// Link: https://leetcode.com/problems/count-the-number-of-special-characters-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1), firstUpper(26, INT_MAX);
        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            if (islower(c)) lastLower[c - 'a'] = i;
            else firstUpper[c - 'A'] = min(firstUpper[c - 'A'], i);
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != INT_MAX && lastLower[i] < firstUpper[i]) cnt++;
        }
        return cnt;
    }
};
