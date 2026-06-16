// Link: https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        // square color = parity of (file letter + rank digit); same parity => same color
        auto color = [](const string& c) { return (c[0] + c[1]) % 2; };
        return color(coordinate1) == color(coordinate2);
    }
};
