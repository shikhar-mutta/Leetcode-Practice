// Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ops = 0, checkSum = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            long long diff = (long long)nums1[i] - nums2[i];
            if (k == 0) {
                if (diff != 0) return -1;
                continue;
            }
            if (diff % k != 0) return -1;
            checkSum += diff;
            if (diff > 0) ops += diff / k;
        }
        if (checkSum != 0) return -1;
        return ops;
    }
};
