// Link: https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            int x = nums[i], s = 0;
            while (x > 0) { s += x % 10; x /= 10; }
            if (s == i) return i;
        }
        return -1;
    }
};
