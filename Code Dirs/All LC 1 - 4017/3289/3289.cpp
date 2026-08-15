// Link: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        vector<int> res;
        for (auto& [k, c] : cnt) if (c == 2) res.push_back(k);
        sort(res.begin(), res.end());
        return res;
    }
};
