// Link: https://leetcode.com/problems/split-strings-by-separator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for (auto &w : words) {
            string cur;
            for (char c : w) {
                if (c == separator) {
                    if (!cur.empty()) ans.push_back(cur);
                    cur.clear();
                } else {
                    cur += c;
                }
            }
            if (!cur.empty()) ans.push_back(cur);
        }
        return ans;
    }
};
