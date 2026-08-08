// Link: https://leetcode.com/problems/expressive-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total chars) SC: O(n)
// Approach: run-length encode s and each word; groups must match in characters and count, with s's group size either equal to the word's or >= 3 and >= word's group size.
class Solution {
    vector<pair<char,int>> encode(const string& str) {
        vector<pair<char,int>> groups;
        int i = 0, n = str.size();
        while (i < n) {
            int j = i;
            while (j < n && str[j] == str[i]) j++;
            groups.push_back({str[i], j-i});
            i = j;
        }
        return groups;
    }
    bool matches(const string& s, const string& w) {
        auto sg = encode(s), wg = encode(w);
        if (sg.size() != wg.size()) return false;
        for (size_t i = 0; i < sg.size(); i++) {
            if (sg[i].first != wg[i].first) return false;
            if (sg[i].second == wg[i].second) continue;
            if (sg[i].second >= 3 && sg[i].second >= wg[i].second) continue;
            return false;
        }
        return true;
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int count = 0;
        for (auto& w : words) if (matches(s, w)) count++;
        return count;
    }
};
