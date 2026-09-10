// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all;
        all.insert(all.end(), nums1.begin(), nums1.end());
        all.insert(all.end(), nums2.begin(), nums2.end());
        sort(all.begin(), all.end());

        
        int n = all.size();
        if (n % 2 == 1)
            return all[n / 2];
        return (all[n / 2 - 1] + all[n / 2]) / 2.0;
    }
};
