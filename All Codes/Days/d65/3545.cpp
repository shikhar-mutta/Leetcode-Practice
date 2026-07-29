// Link: https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        vector<int> freqs;
        for (int c = 0; c < 26; c++) if (cnt[c] > 0) freqs.push_back(cnt[c]);
        sort(freqs.rbegin(), freqs.rend());
        int del = 0;
        for (int i = k; i < (int)freqs.size(); i++) del += freqs[i];
        return del;
    }
};
