// Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string w;
        int idx = 1;
        while (ss >> w) {
            if (w.size() >= searchWord.size() && w.substr(0, searchWord.size()) == searchWord) return idx;
            idx++;
        }
        return -1;
    }
};
