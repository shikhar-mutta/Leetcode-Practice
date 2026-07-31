// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-alternate-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long costForStart(int startParity, vector<int>& posOdd, int n) {
        // target[i] = odd if i%2==startOddOffset
        // startParity: 0 means pattern starts even (odd at odd indices), 1 means pattern starts odd (odd at even indices)
        vector<int> targetOddSlots;
        for (int i = 0; i < n; i++) {
            bool isOddSlot = (startParity == 0) ? (i % 2 == 1) : (i % 2 == 0);
            if (isOddSlot) targetOddSlots.push_back(i);
        }
        long long cost = 0;
        for (size_t i = 0; i < posOdd.size(); i++) cost += llabs(posOdd[i] - targetOddSlots[i]);
        return cost;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> posOdd;
        int countEven = 0, countOdd = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) countEven++;
            else { countOdd++; posOdd.push_back(i); }
        }

        if (abs(countEven - countOdd) > 1) return -1;

        long long best = LLONG_MAX;
        if (countEven == countOdd) {
            best = min(costForStart(0, posOdd, n), costForStart(1, posOdd, n));
        } else if (countEven > countOdd) {
            best = costForStart(0, posOdd, n); // starts even
        } else {
            best = costForStart(1, posOdd, n); // starts odd
        }

        return (int)best;
    }
};
