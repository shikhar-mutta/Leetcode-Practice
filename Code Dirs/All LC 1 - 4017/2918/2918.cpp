// Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;
        for (int x : nums1) { sum1 += x; if (x == 0) zero1++; }
        for (int x : nums2) { sum2 += x; if (x == 0) zero2++; }
        long long min1 = sum1 + zero1;
        long long min2 = sum2 + zero2;
        if (zero1 == 0 && zero2 == 0) return sum1 == sum2 ? sum1 : -1;
        if (zero1 == 0) return min1 >= min2 ? min1 : -1;
        if (zero2 == 0) return min2 >= min1 ? min2 : -1;
        return max(min1, min2);
    }
};
