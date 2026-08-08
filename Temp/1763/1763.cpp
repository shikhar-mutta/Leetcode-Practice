// Link: https://leetcode.com/problems/longest-nice-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNice(const string& s) {
        unordered_set<char> chars(s.begin(), s.end());
        for (char c : chars) {
            if (islower(c) && chars.find(toupper(c)) == chars.end()) return false;
            if (isupper(c) && chars.find(tolower(c)) == chars.end()) return false;
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        int n = s.size();
        string best = "";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string sub = s.substr(i, j - i);
                if ((int)sub.size() > (int)best.size() && isNice(sub)) best = sub;
            }
        }
        return best;
    }
};
