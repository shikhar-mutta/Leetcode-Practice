// Link: https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;
        int groups = n / k;
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        for (auto& [v, c] : cnt) if (c > groups) return false;
        return true;
    }
};
