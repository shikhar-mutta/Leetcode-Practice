// Link: https://leetcode.com/problems/array-partition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort, sum every even-indexed element (min of each pair)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i += 2) sum += nums[i];
        return sum;
    }
};
