// Link: https://leetcode.com/problems/sentence-similarity-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> split(const string& s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) words.push_back(w);
        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> w1 = split(sentence1);
        vector<string> w2 = split(sentence2);
        if (w1.size() > w2.size()) swap(w1, w2);

        int i = 0;
        while (i < (int)w1.size() && w1[i] == w2[i]) i++;
        int j = 0;
        while (j < (int)w1.size() - i && w1[w1.size()-1-j] == w2[w2.size()-1-j]) j++;

        return i + j >= (int)w1.size();
    }
};
