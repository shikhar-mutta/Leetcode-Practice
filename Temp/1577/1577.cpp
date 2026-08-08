// Link: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<int>& source, vector<int>& target) {
        long long count = 0;
        for (int i = 0; i < (int)source.size(); i++) {
            long long sq = (long long)source[i] * source[i];
            for (int j = 0; j < (int)target.size(); j++) {
                for (int k = j + 1; k < (int)target.size(); k++) {
                    if ((long long)target[j] * target[k] == sq) count++;
                }
            }
        }
        return count;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return (int)(countPairs(nums1, nums2) + countPairs(nums2, nums1));
    }
};
