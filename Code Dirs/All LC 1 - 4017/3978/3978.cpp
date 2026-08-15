// Link: https://leetcode.com/problems/unique-middle-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums[nums.size() / 2];
        return count(nums.begin(), nums.end(), mid) == 1;
    }
};
