// Link: https://leetcode.com/problems/find-triangular-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> next;
            for (int i = 0; i + 1 < (int)nums.size(); i++) {
                next.push_back((nums[i] + nums[i + 1]) % 10);
            }
            nums = next;
        }
        return nums[0];
    }
};
