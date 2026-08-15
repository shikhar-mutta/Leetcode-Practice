// Link: https://leetcode.com/problems/robot-return-to-origin/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track net x/y displacement; circle closes iff both are zero.
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else if (c == 'R') x++;
        }
        return x == 0 && y == 0;
    }
};
