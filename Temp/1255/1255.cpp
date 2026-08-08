// Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int avail[26] = {0};
        for (char c : letters) avail[c - 'a']++;
        int n = words.size();
        int best = 0;

        function<void(int, array<int,26>&, int)> dfs = [&](int idx, array<int,26>& used, int cur) {
            best = max(best, cur);
            if (idx == n) return;
            // skip word idx
            dfs(idx + 1, used, cur);
            // try take word idx
            array<int,26> cnt = {};
            bool ok = true;
            for (char c : words[idx]) {
                cnt[c - 'a']++;
                if (used[c - 'a'] + cnt[c - 'a'] > avail[c - 'a']) { ok = false; }
            }
            if (ok) {
                int gain = 0;
                for (int i = 0; i < 26; i++) { used[i] += cnt[i]; gain += cnt[i] * score[i]; }
                dfs(idx + 1, used, cur + gain);
                for (int i = 0; i < 26; i++) used[i] -= cnt[i];
            }
        };

        array<int,26> used = {};
        dfs(0, used, 0);
        return best;
    }
};
