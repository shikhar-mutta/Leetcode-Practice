// Link: https://leetcode.com/problems/smallest-index-with-equal-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i % 10 == nums[i]) return i;
        }
        return -1;
    }
};
