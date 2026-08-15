// Link: https://leetcode.com/problems/apply-operations-to-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        vector<int> result;
        for (int x : nums) if (x != 0) result.push_back(x);
        while ((int)result.size() < n) result.push_back(0);
        return result;
    }
};
