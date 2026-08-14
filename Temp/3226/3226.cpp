// Link: https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        if ((n & k) != k) return -1;
        return __builtin_popcount(n & ~k);
    }
};
