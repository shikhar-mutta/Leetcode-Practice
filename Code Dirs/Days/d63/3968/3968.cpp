// Link: https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: each wildcard can be assigned to whichever axis/direction
// currently has the larger magnitude, always adding exactly 1 to the
// final Manhattan distance regardless of which axis is chosen. So the
// answer is simply the fixed-moves' |netX|+|netY| plus the wildcard
// count.
class Solution {
public:
    int maxDistance(string moves) {
        int x = 0, y = 0, wild = 0;
        for (char c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'L') x--;
            else if (c == 'R') x++;
            else wild++;
        }
        return abs(x) + abs(y) + wild;
    }
};
