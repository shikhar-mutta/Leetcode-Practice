// Link: https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: indices where nums1[i]==nums2[i] must be swapped with something; sum their indices
// as base cost. If one value dominates more than half of these "bad" indices, it can't be fully
// resolved by pairing bad indices among themselves (swapping two same-value bad indices doesn't
// help), so pull in extra good indices (whose value isn't the dominant one) by increasing index
// until the majority is broken. If we run out, impossible.
class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long cost = 0;
        int count = 0;
        unordered_map<int,int> freq;
        int mode = 0, modeFreq = 0;

        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                cost += i;
                count++;
                int f = ++freq[nums1[i]];
                if (f > modeFreq) { modeFreq = f; mode = nums1[i]; }
            }
        }

        for (int i = 0; i < n && (long long)modeFreq * 2 > count; i++) {
            if (nums1[i] != nums2[i] && nums1[i] != mode && nums2[i] != mode) {
                cost += i;
                count++;
            }
        }

        if ((long long)modeFreq * 2 > count) return -1;
        return cost;
    }
};
