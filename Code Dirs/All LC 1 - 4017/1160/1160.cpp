// Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        array<int,26> avail{};
        for (char c : chars) avail[c-'a']++;
        int total = 0;
        for (auto& w : words) {
            array<int,26> cnt{};
            for (char c : w) cnt[c-'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++) if (cnt[i] > avail[i]) { ok = false; break; }
            if (ok) total += w.size();
        }
        return total;
    }
};
