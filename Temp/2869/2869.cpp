// Link: https://leetcode.com/problems/minimum-operations-to-collect-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> need;
        for (int i = 1; i <= k; i++) need.insert(i);
        int ops = 0;
        for (int i = nums.size() - 1; i >= 0 && !need.empty(); i--) {
            need.erase(nums[i]);
            ops++;
        }
        return ops;
    }
};
