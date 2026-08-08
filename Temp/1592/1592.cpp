// Link: https://leetcode.com/problems/rearrange-spaces-between-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int totalSpaces = 0;
        for (char c : text) if (c == ' ') totalSpaces++;

        vector<string> words;
        stringstream ss(text);
        string w;
        while (ss >> w) words.push_back(w);

        string res;
        if (words.size() == 1) {
            res = words[0] + string(totalSpaces, ' ');
            return res;
        }

        int gap = totalSpaces / (words.size() - 1);
        int extra = totalSpaces % (words.size() - 1);
        for (int i = 0; i < (int)words.size(); i++) {
            res += words[i];
            if (i != (int)words.size() - 1) res += string(gap, ' ');
        }
        res += string(extra, ' ');
        return res;
    }
};
