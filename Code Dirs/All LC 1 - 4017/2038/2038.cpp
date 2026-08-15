// Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aliceMoves = 0, bobMoves = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && colors[j] == colors[i]) j++;
            int len = j - i;
            if (len >= 3) {
                if (colors[i] == 'A') aliceMoves += len - 2;
                else bobMoves += len - 2;
            }
            i = j;
        }
        return aliceMoves > bobMoves;
    }
};
