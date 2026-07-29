// Link: https://leetcode.com/problems/count-subarrays-with-median-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: every valid subarray must contain the (unique) occurrence of k. Score elements
// +1 (>k), -1 (<k), 0 (==k). Count cumulative balance walking left from pos, store in a map;
// walking right from pos, for balance b a valid subarray needs left balance -b or 1-b
// (median==k means equal counts, or one extra smaller since k is the lower median on ties).
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int pos = -1;
        for (int i = 0; i < n; i++) if (nums[i] == k) { pos = i; break; }

        unordered_map<int,int> leftCount;
        int balance = 0;
        leftCount[0] = 1;
        for (int i = pos - 1; i >= 0; i--) {
            balance += (nums[i] > k) ? 1 : -1;
            leftCount[balance]++;
        }

        long long ans = 0;
        balance = 0;
        for (int i = pos; i < n; i++) {
            if (i > pos) balance += (nums[i] > k) ? 1 : -1;
            auto it1 = leftCount.find(-balance);
            if (it1 != leftCount.end()) ans += it1->second;
            auto it2 = leftCount.find(1 - balance);
            if (it2 != leftCount.end()) ans += it2->second;
        }
        return (int)ans;
    }
};
