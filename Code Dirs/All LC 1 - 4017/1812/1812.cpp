// Link: https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = coordinates[0] - 'a';
        int row = coordinates[1] - '1';
        return (col + row) % 2 == 1;
    }
};
