// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: reverse each space-delimited word in place
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i <= (int)s.size(); i++) {
            if (i == (int)s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
