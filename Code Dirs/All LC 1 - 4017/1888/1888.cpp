// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;
        int diff0 = 0, diff1 = 0;
        int best = INT_MAX;
        for (int i = 0; i < (int)t.size(); i++) {
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            if (t[i] != expected0) diff0++;
            if (t[i] != expected1) diff1++;

            if (i >= n) {
                int j = i - n;
                char old0 = (j % 2 == 0) ? '0' : '1';
                char old1 = (j % 2 == 0) ? '1' : '0';
                if (t[j] != old0) diff0--;
                if (t[j] != old1) diff1--;
            }

            if (i >= n - 1) {
                best = min(best, min(diff0, diff1));
            }
        }
        return best;
    }
};
