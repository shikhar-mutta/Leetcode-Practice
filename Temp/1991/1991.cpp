// Link: https://leetcode.com/problems/find-the-middle-index-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        int leftSum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (leftSum == total - leftSum - nums[i]) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
