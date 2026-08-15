// Link: https://leetcode.com/problems/intersection-of-multiple-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> cnt;
        for (auto& row : nums) for (int x : row) cnt[x]++;
        int n = nums.size();
        vector<int> res;
        for (auto& [k, c] : cnt) if (c == n) res.push_back(k);
        sort(res.begin(), res.end());
        return res;
    }
};
