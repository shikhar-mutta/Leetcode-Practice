// Link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        for (auto& [k, c] : cnt) if (c % 2 != 0) return false;
        return true;
    }
};
