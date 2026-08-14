// Link: https://leetcode.com/problems/maximum-size-of-a-set-after-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        int common = 0;
        for (int x : s1) if (s2.count(x)) common++;

        int half = nums1.size() / 2;
        int uniqueOnly1 = s1.size() - common;
        int uniqueOnly2 = s2.size() - common;

        int a = min(half, uniqueOnly1);
        int rem1 = half - a;
        int b = min(half, uniqueOnly2);
        int rem2 = half - b;

        int commonUsed = min(common, rem1 + rem2);
        return a + b + commonUsed;
    }
};
