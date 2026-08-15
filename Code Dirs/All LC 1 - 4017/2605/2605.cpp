// Link: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        int common = 10;
        for (int x : s1) if (s2.count(x)) common = min(common, x);
        if (common != 10) return common;

        int min1 = *min_element(nums1.begin(), nums1.end());
        int min2 = *min_element(nums2.begin(), nums2.end());
        if (min1 > min2) swap(min1, min2);
        return min1 * 10 + min2;
    }
};
