// Link: https://leetcode.com/problems/widest-pair-of-indices-with-equal-range-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> firstIdx;
        firstIdx[0] = -1;
        int diff = 0;
        int best = 0;
        for (int i = 0; i < (int)nums1.size(); i++) {
            diff += nums1[i] - nums2[i];
            if (firstIdx.count(diff)) {
                best = max(best, i - firstIdx[diff]);
            } else {
                firstIdx[diff] = i;
            }
        }
        return best;
    }
};
