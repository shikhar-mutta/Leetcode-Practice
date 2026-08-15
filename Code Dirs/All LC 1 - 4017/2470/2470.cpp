// Link: https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            long long curLcm = 1;
            for (int j = i; j < n; j++) {
                curLcm = lcm(curLcm, (long long)nums[j]);
                if (curLcm > k) break;
                if (curLcm == k) count++;
            }
        }
        return count;
    }
};
