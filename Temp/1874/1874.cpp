// Link: https://leetcode.com/problems/minimize-product-sum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.rbegin(), nums2.rend());
        long long sum = 0;
        for (int i = 0; i < (int)nums1.size(); i++) sum += (long long)nums1[i] * nums2[i];
        return (int)sum;
    }
};
