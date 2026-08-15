// Link: https://leetcode.com/problems/find-the-number-of-good-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int maxVal = *max_element(nums1.begin(), nums1.end());
        unordered_map<int,int> freq1;
        for (int x : nums1) freq1[x]++;

        unordered_map<int,int> freq2;
        for (int x : nums2) freq2[x]++;

        long long ans = 0;
        for (auto& [b, cntB] : freq2) {
            long long target = (long long)b * k;
            if (target == 0 || target > maxVal) continue;
            long long cntDivisible = 0;
            for (long long m = target; m <= maxVal; m += target) {
                auto it = freq1.find((int)m);
                if (it != freq1.end()) cntDivisible += it->second;
            }
            ans += cntDivisible * cntB;
        }
        return ans;
    }
};
