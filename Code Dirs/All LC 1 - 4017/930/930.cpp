// Link: https://leetcode.com/problems/binary-subarrays-with-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0, sum = 0, res = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
