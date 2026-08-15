// Link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        return k * maxVal + k * (k - 1) / 2;
    }
};
