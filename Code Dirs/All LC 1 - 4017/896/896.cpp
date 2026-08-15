// Link: https://leetcode.com/problems/monotonic-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] > nums[i-1]) dec = false;
            if (nums[i] < nums[i-1]) inc = false;
        }
        return inc || dec;
    }
};
