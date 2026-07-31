// Link: https://leetcode.com/problems/find-minimum-log-transportation-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long total = 0;
        if (n > k) total += (long long)k * (n - k);
        if (m > k) total += (long long)k * (m - k);
        return total;
    }
};
