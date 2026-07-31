// Link: https://leetcode.com/problems/maximum-k-to-sort-a-permutation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int result = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != i) {
                result = (result == -1) ? nums[i] : (result & nums[i]);
            }
        }
        return result == -1 ? 0 : result;
    }
};
