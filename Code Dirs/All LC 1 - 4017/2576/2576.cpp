// Link: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        for (int j = n / 2; j < n; j++) {
            if (2 * nums[i] <= nums[j]) i++;
        }
        return i * 2;
    }
};
