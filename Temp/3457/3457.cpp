// Link: https://leetcode.com/problems/eat-pizzas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        sort(pizzas.rbegin(), pizzas.rend());
        int n = pizzas.size();
        int days = n / 4;
        int oddDays = (days + 1) / 2;
        int evenDays = days / 2;

        long long gain = 0;
        int idx = 0;
        for (int i = 0; i < oddDays; i++) {
            gain += pizzas[idx];
            idx++;
        }
        for (int i = 0; i < evenDays; i++) {
            idx += 1;
            gain += pizzas[idx];
            idx++;
        }
        return gain;
    }
};
