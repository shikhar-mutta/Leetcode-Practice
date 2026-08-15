// Link: https://leetcode.com/problems/report-spam-message/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (auto& w : message) {
            if (banned.count(w)) {
                cnt++;
                if (cnt >= 2) return true;
            }
        }
        return false;
    }
};
