// Link: https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int cur = 0, streak = 0;
        for (int i = 1; i < n; i++) {
            if (skills[cur] > skills[i]) {
                streak++;
            } else {
                cur = i;
                streak = 1;
            }
            if (streak >= k) return cur;
        }
        return cur;
    }
};
