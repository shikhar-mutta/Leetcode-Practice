// Link: https://leetcode.com/problems/circular-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string w;
        while (ss >> w) words.push_back(w);

        int n = words.size();
        for (int i = 0; i < n; i++) {
            if (words[i].back() != words[(i+1) % n].front()) return false;
        }
        return true;
    }
};
