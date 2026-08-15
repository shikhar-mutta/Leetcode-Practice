// Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        int best = 0;
        while (i < n && j < m) {
            if (nums1[i] > nums2[j]) {
                i++;
            } else {
                best = max(best, j - i);
                j++;
            }
        }
        return best;
    }
};
