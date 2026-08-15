// Link: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        for (int pens = 0; (long long)pens * cost1 <= total; pens++) {
            long long remaining = total - (long long)pens * cost1;
            ways += remaining / cost2 + 1;
        }
        return ways;
    }
};
