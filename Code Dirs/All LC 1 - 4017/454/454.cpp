// Link: https://leetcode.com/problems/4sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: precompute all pair-sums of nums1+nums2 into a hashmap, then
// for each pair-sum of nums3+nums4 look up the complement
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumCount;
        for (int a : nums1)
            for (int b : nums2)
                sumCount[a + b]++;

        int count = 0;
        for (int c : nums3)
            for (int d : nums4)
                if (sumCount.count(-(c + d))) count += sumCount[-(c + d)];
        return count;
    }
};
