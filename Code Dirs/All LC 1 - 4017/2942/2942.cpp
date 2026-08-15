// Link: https://leetcode.com/problems/find-words-containing-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < (int)words.size(); i++)
            if (words[i].find(x) != string::npos) res.push_back(i);
        return res;
    }
};
