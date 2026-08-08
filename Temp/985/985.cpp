// Link: https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for (int x : nums) if (x % 2 == 0) sum += x;
        vector<int> res;
        for (auto& q : queries) {
            int val = q[0], idx = q[1];
            if (nums[idx] % 2 == 0) sum -= nums[idx];
            nums[idx] += val;
            if (nums[idx] % 2 == 0) sum += nums[idx];
            res.push_back(sum);
        }
        return res;
    }
};
