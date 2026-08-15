// Link: https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChairs(string s) {
        int cur = 0, maxC = 0;
        for (char c : s) {
            cur += (c == 'E') ? 1 : -1;
            maxC = max(maxC, cur);
        }
        return maxC;
    }
};
