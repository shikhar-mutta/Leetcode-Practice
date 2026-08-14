// Link: https://leetcode.com/problems/replace-elements-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> pos;
        for (int i = 0; i < (int)nums.size(); i++) pos[nums[i]] = i;
        for (auto& op : operations) {
            int idx = pos[op[0]];
            nums[idx] = op[1];
            pos.erase(op[0]);
            pos[op[1]] = idx;
        }
        return nums;
    }
};
