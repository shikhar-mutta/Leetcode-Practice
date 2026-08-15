// Link: https://leetcode.com/problems/word-pattern/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: split s into words, bijective map between pattern chars and words
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) words.push_back(w);
        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> c2w;
        unordered_map<string, char> w2c;
        for (int i = 0; i < (int)pattern.size(); i++) {
            char c = pattern[i];
            if (c2w.count(c) && c2w[c] != words[i]) return false;
            if (w2c.count(words[i]) && w2c[words[i]] != c) return false;
            c2w[c] = words[i];
            w2c[words[i]] = c;
        }
        return true;
    }
};
