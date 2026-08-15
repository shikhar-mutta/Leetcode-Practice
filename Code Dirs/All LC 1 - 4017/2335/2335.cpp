// Link: https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        int a = amount[2], b = amount[1], c = amount[0];
        if (a > b + c) return a;
        return (a + b + c + 1) / 2;
    }
};
