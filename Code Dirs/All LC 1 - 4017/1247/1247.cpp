// Link: https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for (int i = 0; i < (int)s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x') xy++;
            else yx++;
        }
        if ((xy + yx) % 2 != 0) return -1;
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};
