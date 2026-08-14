// Link: https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                for (int k = j+1; k < n; k++)
                    if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k]) count++;
        return count;
    }
};
