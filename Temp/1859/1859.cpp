// Link: https://leetcode.com/problems/sorting-the-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10);
        stringstream ss(s);
        string w;
        int maxIdx = 0;
        while (ss >> w) {
            int idx = w.back() - '0';
            words[idx] = w.substr(0, w.size() - 1);
            maxIdx = max(maxIdx, idx);
        }
        string res;
        for (int i = 1; i <= maxIdx; i++) {
            if (i > 1) res += " ";
            res += words[i];
        }
        return res;
    }
};
