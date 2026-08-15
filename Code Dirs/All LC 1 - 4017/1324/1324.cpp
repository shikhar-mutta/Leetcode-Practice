// Link: https://leetcode.com/problems/print-words-vertically/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) words.push_back(w);

        int maxLen = 0;
        for (auto& word : words) maxLen = max(maxLen, (int)word.size());

        vector<string> res;
        for (int i = 0; i < maxLen; i++) {
            string row;
            for (auto& word : words) {
                row += (i < (int)word.size()) ? word[i] : ' ';
            }
            while (!row.empty() && row.back() == ' ') row.pop_back();
            res.push_back(row);
        }
        return res;
    }
};
