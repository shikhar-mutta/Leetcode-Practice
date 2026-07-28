// Link: https://leetcode.com/problems/get-the-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        const long long MOD = 1e9 + 7;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        long long sum1 = 0, sum2 = 0, res = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) sum1 += nums1[i++];
            else if (nums1[i] > nums2[j]) sum2 += nums2[j++];
            else {
                res += max(sum1, sum2) + nums1[i];
                sum1 = sum2 = 0;
                i++; j++;
            }
        }
        while (i < n) sum1 += nums1[i++];
        while (j < m) sum2 += nums2[j++];
        res += max(sum1, sum2);
        return (int)(res % MOD);
    }
};
