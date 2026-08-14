// Link: https://leetcode.com/problems/find-the-pivot-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        int x = (int)round(sqrt((double)total));
        if (x * x == total) return x;
        return -1;
    }
};
