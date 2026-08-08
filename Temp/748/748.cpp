// Link: https://leetcode.com/problems/shortest-completing-word/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*L) SC: O(1)
// Approach: build required letter-count array from license plate letters (lowercased); for each word, check its letter counts cover requirements; track shortest (first on tie).
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int need[26] = {0};
        for (char c : licensePlate) if (isalpha(c)) need[tolower(c)-'a']++;
        string best = "";
        for (auto& w : words) {
            int cnt[26] = {0};
            for (char c : w) cnt[tolower(c)-'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) if (cnt[i] < need[i]) { ok = false; break; }
            if (ok && (best.empty() || w.size() < best.size())) best = w;
        }
        return best;
    }
};
