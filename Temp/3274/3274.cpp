// Link: https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int p1 = (coordinate1[0] - 'a' + coordinate1[1] - '0') % 2;
        int p2 = (coordinate2[0] - 'a' + coordinate2[1] - '0') % 2;
        return p1 == p2;
    }
};
