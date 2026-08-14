// Link: https://leetcode.com/problems/find-the-number-of-winning-players/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<array<int,11>> cnt(n);
        for (auto& a : cnt) a.fill(0);
        for (auto& p : pick) cnt[p[0]][p[1]]++;
        int wins = 0;
        for (int i = 0; i < n; i++) {
            bool win = false;
            for (int c = 0; c < 11; c++) {
                if (cnt[i][c] >= i + 1) { win = true; break; }
            }
            if (win) wins++;
        }
        return wins;
    }
};
