// Link: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> positives;
        int maxVal = INT_MIN;
        for (int x : nums) {
            maxVal = max(maxVal, x);
            if (x > 0) positives.insert(x);
        }
        if (positives.empty()) return maxVal;
        int sum = 0;
        for (int x : positives) sum += x;
        return sum;
    }
};
