// Link: https://leetcode.com/problems/sort-array-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            if (nums[lo] % 2 == 0) lo++;
            else swap(nums[lo], nums[hi--]);
        }
        return nums;
    }
};
