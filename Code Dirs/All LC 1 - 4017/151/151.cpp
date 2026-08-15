// Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: split on whitespace into words (stringstream skips extra spaces automatically), then join reversed
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        string w;
        while (ss >> w) words.push_back(w);
        reverse(words.begin(), words.end());
        string res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i) res += " ";
            res += words[i];
        }
        return res;
    }
};
