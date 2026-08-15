// Link: https://leetcode.com/problems/count-subarrays-with-median-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = -1;
        for (int i = 0; i < n; i++) if (nums[i] == k) { idx = i; break; }

        unordered_map<int,int> rightCount;
        int balance = 0;
        rightCount[0] = 1;
        for (int i = idx + 1; i < n; i++) {
            balance += (nums[i] > k) - (nums[i] < k);
            rightCount[balance]++;
        }

        long long ans = 0;
        balance = 0;
        ans += rightCount[0] + rightCount[1];
        for (int i = idx - 1; i >= 0; i--) {
            balance += (nums[i] > k) - (nums[i] < k);
            ans += rightCount[-balance] + rightCount[1 - balance];
        }
        return (int)ans;
    }
};
