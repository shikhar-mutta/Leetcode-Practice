// Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int freq[26] = {0};
        for (auto& w : words) for (char c : w) freq[c - 'a']++;
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] % n != 0) return false;
        }
        return true;
    }
};
