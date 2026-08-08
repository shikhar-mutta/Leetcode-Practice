// Link: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        for (int x : nums) {
            sum += x;
            minSum = min(minSum, sum);
        }
        return 1 - minSum;
    }
};
