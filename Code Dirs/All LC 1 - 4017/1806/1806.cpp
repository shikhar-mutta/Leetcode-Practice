// Link: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int ops = 0;
        do {
            if (pos < n / 2) pos = 2 * pos;
            else pos = 2 * (pos - n / 2) + 1;
            ops++;
        } while (pos != 1);
        return ops;
    }
};
