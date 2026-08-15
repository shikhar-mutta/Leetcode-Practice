// Link: https://leetcode.com/problems/word-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        array<int,26> maxReq{};
        for (auto& w : words2) {
            array<int,26> cnt{};
            for (char c : w) cnt[c-'a']++;
            for (int i = 0; i < 26; i++) maxReq[i] = max(maxReq[i], cnt[i]);
        }
        vector<string> res;
        for (auto& w : words1) {
            array<int,26> cnt{};
            for (char c : w) cnt[c-'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) if (cnt[i] < maxReq[i]) { ok = false; break; }
            if (ok) res.push_back(w);
        }
        return res;
    }
};
