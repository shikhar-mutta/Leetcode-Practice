// Link: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;
        if (sum1 == sum2) return 0;
        if (sum1 > sum2) { swap(sum1, sum2); swap(nums1, nums2); }
        long long diff = sum2 - sum1;

        vector<int> gains;
        for (int x : nums1) gains.push_back(6 - x);
        for (int x : nums2) gains.push_back(x - 1);
        sort(gains.rbegin(), gains.rend());

        int ops = 0;
        for (int g : gains) {
            if (diff <= 0) break;
            diff -= g;
            ops++;
        }
        return diff <= 0 ? ops : -1;
    }
};
