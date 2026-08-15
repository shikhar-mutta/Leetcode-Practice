// Link: https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        long long S = pre[n];

        unordered_map<long long,int> cntAll;
        for (int i = 1; i <= n - 1; i++) cntAll[pre[i]]++;

        int ans = 0;
        if (S % 2 == 0) ans = cntAll[S / 2];

        unordered_map<long long,int> leftMap, rightMap = cntAll;
        for (int j = 0; j < n; j++) {
            long long delta = (long long)k - nums[j];
            long long target1 = S + delta;
            int cntFromLeft = (target1 % 2 == 0) ? leftMap[target1 / 2] : 0;
            long long target2 = S - delta;
            int cntFromRight = (target2 % 2 == 0) ? rightMap[target2 / 2] : 0;
            ans = max(ans, cntFromLeft + cntFromRight);
            if (j + 1 <= n - 1) {
                rightMap[pre[j + 1]]--;
                leftMap[pre[j + 1]]++;
            }
        }
        return ans;
    }
};
