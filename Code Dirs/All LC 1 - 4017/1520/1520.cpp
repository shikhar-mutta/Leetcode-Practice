// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1) continue;
            int l = first[c], r = last[c];
            bool changed = true;
            bool valid = true;
            while (changed) {
                changed = false;
                for (int k = l; k <= r; k++) {
                    int ck = s[k] - 'a';
                    if (first[ck] < l) { l = first[ck]; changed = true; }
                    if (last[ck] > r) { r = last[ck]; changed = true; }
                }
            }
            if (l == first[c]) intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });

        vector<string> res;
        int lastEnd = -1;
        for (auto& [l, r] : intervals) {
            if (l > lastEnd) {
                res.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }
        return res;
    }
};
