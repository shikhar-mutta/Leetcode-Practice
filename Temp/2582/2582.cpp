// Link: https://leetcode.com/problems/pass-the-pillow/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = time % (2 * (n - 1));
        if (cycle < n) return cycle + 1;
        return 2 * (n - 1) - cycle + 1;
    }
};
