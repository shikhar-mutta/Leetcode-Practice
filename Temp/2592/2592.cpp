// Link: https://leetcode.com/problems/maximize-greatness-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (int j = 0; j < (int)nums.size(); j++) {
            if (nums[j] > nums[i]) i++;
        }
        return i;
    }
};
