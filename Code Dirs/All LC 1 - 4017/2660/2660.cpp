// Link: https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeScore(vector<int>& player) {
        int n = player.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            int mult = 1;
            if ((i >= 1 && player[i-1] == 10) || (i >= 2 && player[i-2] == 10)) mult = 2;
            total += player[i] * mult;
        }
        return total;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = computeScore(player1);
        int s2 = computeScore(player2);
        if (s1 > s2) return 1;
        if (s2 > s1) return 2;
        return 0;
    }
};
