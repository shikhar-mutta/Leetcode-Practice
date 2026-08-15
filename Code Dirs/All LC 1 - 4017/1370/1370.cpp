// Link: https://leetcode.com/problems/increasing-decreasing-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string res;
        while ((int)res.size() < (int)s.size()) {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 0) { res += char('a' + i); cnt[i]--; }
            }
            for (int i = 25; i >= 0; i--) {
                if (cnt[i] > 0) { res += char('a' + i); cnt[i]--; }
            }
        }
        return res;
    }
};
