// Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long total = 0;
        long long runLen = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && prices[i] == prices[i - 1] - 1) {
                runLen++;
            } else {
                total += runLen * (runLen + 1) / 2;
                runLen = 1;
            }
        }
        return total;
    }
};
