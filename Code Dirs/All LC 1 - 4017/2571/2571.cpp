// Link: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(int n) {
        long long x = n;
        int ops = 0;
        while (x > 0) {
            if (x & 1) {
                if ((x & 3) == 3) x++;
                else x--;
                ops++;
            }
            x >>= 1;
        }
        return ops;
    }
};
