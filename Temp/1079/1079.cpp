// Link: https://leetcode.com/problems/letter-tile-possibilities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTilePossibilities(string tiles) {
        array<int,26> cnt{};
        for (char c : tiles) cnt[c-'A']++;
        return dfs(cnt);
    }

private:
    int dfs(array<int,26>& cnt) {
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            cnt[i]--;
            total++;
            total += dfs(cnt);
            cnt[i]++;
        }
        return total;
    }
};
