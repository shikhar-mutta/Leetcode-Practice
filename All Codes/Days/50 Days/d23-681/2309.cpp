// Link: https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        bool lower[26] = {false}, upper[26] = {false};
        for (char c : s) {
            if (islower(c)) lower[c - 'a'] = true;
            else            upper[c - 'A'] = true;
        }
        // scan from 'Z' down; first letter present in both cases is the answer
        for (int i = 25; i >= 0; i--)
            if (lower[i] && upper[i]) return string(1, 'A' + i);
        return "";
    }
};
