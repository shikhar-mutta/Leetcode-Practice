// Link: https://leetcode.com/problems/rearrange-words-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w) words.push_back(w);
        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        words[0][0] = toupper(words[0][0]);
        string res;
        for (int i = 0; i < (int)words.size(); i++) {
            if (i) res += " ";
            res += words[i];
        }
        return res;
    }
};
