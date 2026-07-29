// Link: https://leetcode.com/problems/count-the-number-of-good-partitions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: every occurrence of the same value must stay in the same partition segment, so merge
// [firstOcc,lastOcc] intervals greedily left to right (like merge-intervals) to find the c
// maximal forced blocks. Between consecutive blocks there's a free choice to split or not, giving
// 2^(c-1) good partitions.
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        const long long MOD = 1e9+7;
        int n = nums.size();
        unordered_map<int,int> lastOcc;
        for (int i = 0; i < n; i++) lastOcc[nums[i]] = i;

        int blocks = 0;
        int reach = -1;
        for (int i = 0; i < n; i++) {
            if (i > reach) blocks++;
            reach = max(reach, lastOcc[nums[i]]);
        }

        long long ans = 1;
        for (int i = 0; i < blocks - 1; i++) ans = ans * 2 % MOD;
        return (int)ans;
    }
};
