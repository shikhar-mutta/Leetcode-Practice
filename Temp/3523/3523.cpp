// Link: https://leetcode.com/problems/make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int t = nums[0];
        int c = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (t <= nums[i]) {
                c++;
                t = nums[i];
            }
        }
        return c;
    }
};
