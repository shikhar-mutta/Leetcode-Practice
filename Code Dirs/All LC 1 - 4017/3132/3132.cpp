// Link: https://leetcode.com/problems/find-the-integer-added-to-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums1, vector<int>& nums2, int x) {
        int j = 0;
        int missed = 0;
        for (int i = 0; i < (int)nums1.size() && j < (int)nums2.size(); i++) {
            if (nums1[i] + x == nums2[j]) j++;
        }
        return j == (int)nums2.size();
    }

    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int best = INT_MAX;
        for (int i = 0; i < 3; i++) {
            int x = nums2[0] - nums1[i];
            if (check(nums1, nums2, x)) best = min(best, x);
        }
        return best;
    }
};
