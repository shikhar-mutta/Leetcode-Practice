// Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        sort(freq.rbegin(), freq.rend());
        int deletions = 0;
        for (int i = 1; i < 26; i++) {
            while (freq[i] > 0 && freq[i] >= freq[i-1]) {
                freq[i]--;
                deletions++;
            }
        }
        return deletions;
    }
};
