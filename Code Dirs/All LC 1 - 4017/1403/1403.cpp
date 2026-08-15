// Link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int total = 0;
        for (int x : nums) total += x;
        vector<int> res;
        int sum = 0;
        for (int x : nums) {
            res.push_back(x);
            sum += x;
            if (sum > total - sum) break;
        }
        return res;
    }
};
