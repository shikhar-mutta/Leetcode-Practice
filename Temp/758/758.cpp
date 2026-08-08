// Link: https://leetcode.com/problems/bold-words-in-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*k) SC: O(n)
// Approach: mark boolean array of positions covered by any word occurrence, then merge consecutive marked runs into <b> tags.
class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int n = s.size();
        vector<bool> bold(n, false);
        for (auto& w : words) {
            size_t pos = s.find(w);
            while (pos != string::npos) {
                for (size_t i = pos; i < pos + w.size(); i++) bold[i] = true;
                pos = s.find(w, pos+1);
            }
        }
        string res;
        int i = 0;
        while (i < n) {
            if (bold[i]) {
                res += "<b>";
                int j = i;
                while (j < n && bold[j]) j++;
                res += s.substr(i, j-i);
                res += "</b>";
                i = j;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};
