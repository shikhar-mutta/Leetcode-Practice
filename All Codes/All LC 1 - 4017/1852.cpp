// Link: https://leetcode.com/problems/distinct-numbers-in-each-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (i >= k) {
                freq[nums[i-k]]--;
                if (freq[nums[i-k]] == 0) freq.erase(nums[i-k]);
            }
            if (i >= k - 1) res.push_back(freq.size());
        }
        return res;
    }
};
