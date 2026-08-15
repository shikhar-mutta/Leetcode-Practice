// Link: https://leetcode.com/problems/transform-array-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for (int& x : nums) x = (x % 2 == 0) ? 0 : 1;
        sort(nums.begin(), nums.end());
        return nums;
    }
};
