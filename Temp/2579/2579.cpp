// Link: https://leetcode.com/problems/count-total-number-of-colored-cells/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        long long nn = n;
        return 2 * nn * nn - 2 * nn + 1;
    }
};
