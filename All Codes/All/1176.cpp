// Link: https://leetcode.com/problems/diet-plan-performance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int n = calories.size();
        int sum = 0;
        for (int i = 0; i < k; i++) sum += calories[i];
        int points = 0;
        auto eval = [&](int s) {
            if (s < lower) points--;
            else if (s > upper) points++;
        };
        eval(sum);
        for (int i = k; i < n; i++) {
            sum += calories[i] - calories[i-k];
            eval(sum);
        }
        return points;
    }
};
