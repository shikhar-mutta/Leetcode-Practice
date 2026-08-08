// Link: https://leetcode.com/problems/diagonal-traverse-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<pair<int,int>>> diagonals;
        for (int i = 0; i < (int)nums.size(); i++) {
            for (int j = 0; j < (int)nums[i].size(); j++) {
                int d = i + j;
                if (d >= (int)diagonals.size()) diagonals.resize(d + 1);
                diagonals[d].push_back({i, j});
            }
        }
        vector<int> res;
        for (auto& diag : diagonals) {
            for (auto it = diag.rbegin(); it != diag.rend(); ++it) {
                res.push_back(nums[it->first][it->second]);
            }
        }
        return res;
    }
};
