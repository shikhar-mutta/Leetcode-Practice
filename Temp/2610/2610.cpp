// Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        vector<vector<int>> ans;
        for (auto &[val, cnt] : freq) {
            for (int i = 0; i < cnt; i++) {
                if ((int)ans.size() <= i) ans.push_back({});
                ans[i].push_back(val);
            }
        }
        return ans;
    }
};
