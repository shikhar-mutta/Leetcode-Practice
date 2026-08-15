// Link: https://leetcode.com/problems/apply-operations-to-make-string-empty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> freq(26, 0), lastIdx(26, -1);
        for (int i = 0; i < (int)s.size(); i++) {
            freq[s[i]-'a']++;
            lastIdx[s[i]-'a'] = i;
        }
        int maxF = *max_element(freq.begin(), freq.end());
        vector<pair<int,char>> chars;
        for (int c = 0; c < 26; c++) {
            if (freq[c] == maxF) chars.push_back({lastIdx[c], (char)('a'+c)});
        }
        sort(chars.begin(), chars.end());
        string res;
        for (auto& [idx, c] : chars) res += c;
        return res;
    }
};
