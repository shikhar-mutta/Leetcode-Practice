// Link: https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefK(n + 1, 0);
        int countK = 0;
        for (int i = 0; i < n; i++) {
            prefK[i + 1] = prefK[i] + (nums[i] == k ? 1 : 0);
            if (nums[i] == k) countK++;
        }

        unordered_map<int,int> lastOcc, prevDp;
        int best = 0;
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if (v == k) continue;
            auto it = lastOcc.find(v);
            int dp;
            if (it == lastOcc.end()) {
                dp = 1;
            } else {
                int p1 = it->second;
                int kBetween = prefK[i] - prefK[p1 + 1];
                dp = max(prevDp[v] - kBetween, 0) + 1;
            }
            lastOcc[v] = i;
            prevDp[v] = dp;
            best = max(best, dp);
        }

        return countK + best;
    }
};
