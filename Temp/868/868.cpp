// Link: https://leetcode.com/problems/binary-gap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int prev = -1, i = 0, best = 0;
        while (n) {
            if (n & 1) {
                if (prev != -1) best = max(best, i - prev);
                prev = i;
            }
            n >>= 1;
            i++;
        }
        return best;
    }
};
