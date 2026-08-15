// Link: https://leetcode.com/problems/make-a-square-with-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int w = 0, b = 0;
                for (int di = 0; di < 2; di++)
                    for (int dj = 0; dj < 2; dj++)
                        (grid[i+di][j+dj] == 'W' ? w : b)++;
                if (w != 2 || b != 2) return true;
            }
        }
        return false;
    }
};
