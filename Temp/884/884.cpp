// Link: https://leetcode.com/problems/uncommon-words-from-two-sentences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> cnt;
        vector<string> order;
        stringstream ss(s1 + " " + s2);
        string w;
        while (ss >> w) {
            if (cnt.find(w) == cnt.end()) order.push_back(w);
            cnt[w]++;
        }
        vector<string> res;
        for (auto& word : order) if (cnt[word] == 1) res.push_back(word);
        return res;
    }
};
