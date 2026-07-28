// Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
    }
};
