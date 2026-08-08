// Link: https://leetcode.com/problems/ways-to-make-a-fair-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefEven(n + 1, 0), prefOdd(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefEven[i+1] = prefEven[i] + (i % 2 == 0 ? nums[i] : 0);
            prefOdd[i+1] = prefOdd[i] + (i % 2 == 1 ? nums[i] : 0);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long leftEven = prefEven[i], leftOdd = prefOdd[i];
            long long rightEvenTotal = prefEven[n] - prefEven[i+1];
            long long rightOddTotal = prefOdd[n] - prefOdd[i+1];
            // after removing i, indices shift: original even positions after i become odd and vice versa
            long long newEven = leftEven + rightOddTotal;
            long long newOdd = leftOdd + rightEvenTotal;
            if (newEven == newOdd) count++;
        }
        return count;
    }
};
