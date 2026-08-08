// Link: https://leetcode.com/problems/find-common-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<int,26> minCnt;
        minCnt.fill(INT_MAX);
        for (auto& w : words) {
            array<int,26> cnt{};
            for (char c : w) cnt[c-'a']++;
            for (int i = 0; i < 26; i++) minCnt[i] = min(minCnt[i], cnt[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < minCnt[i]; j++)
                res.push_back(string(1, 'a'+i));
        return res;
    }
};
