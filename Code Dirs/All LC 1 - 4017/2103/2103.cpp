// Link: https://leetcode.com/problems/rings-and-rods/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int mask[10] = {0};
        for (int i = 0; i < (int)rings.size(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            if (color == 'R') mask[rod] |= 1;
            else if (color == 'G') mask[rod] |= 2;
            else mask[rod] |= 4;
        }
        int count = 0;
        for (int i = 0; i < 10; i++) if (mask[i] == 7) count++;
        return count;
    }
};
