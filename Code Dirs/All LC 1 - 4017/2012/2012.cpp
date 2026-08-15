// Link: https://leetcode.com/problems/sum-of-beauty-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefMax(n), sufMin(n);
        prefMax[0] = nums[0];
        for (int i = 1; i < n; i++) prefMax[i] = max(prefMax[i-1], nums[i]);
        sufMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) sufMin[i] = min(sufMin[i+1], nums[i]);
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > prefMax[i-1] && nums[i] < sufMin[i+1]) ans += 2;
            else if (nums[i] > nums[i-1] && nums[i] < nums[i+1]) ans += 1;
        }
        return ans;
    }
};
