// Link: https://leetcode.com/problems/minimum-total-cost-to-make-arrays-unequal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long totalCost = 0;
        int swapCount = 0;
        unordered_map<int,int> freq;
        int maxFreqVal = 0, maxFreq = 0;
        vector<bool> inBadSet(n, false);

        for (int i = 0; i < n; i++) {
            if (nums1[i] == nums2[i]) {
                totalCost += i;
                swapCount++;
                inBadSet[i] = true;
                int v = nums1[i];
                freq[v]++;
                if (freq[v] > maxFreq) {
                    maxFreq = freq[v];
                    maxFreqVal = v;
                }
            }
        }

        for (int i = 0; i < n && maxFreq * 2 > swapCount; i++) {
            if (inBadSet[i]) continue;
            if (nums1[i] != maxFreqVal && nums2[i] != maxFreqVal) {
                totalCost += i;
                swapCount++;
            }
        }

        if (maxFreq * 2 > swapCount) return -1;
        return totalCost;
    }
};
