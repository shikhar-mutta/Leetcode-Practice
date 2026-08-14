// Link: https://leetcode.com/problems/the-number-of-beautiful-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> freq;

    int backtrack(vector<int>& nums, int k, int idx) {
        if (idx == (int)nums.size()) return 1;
        int count = backtrack(nums, k, idx + 1);
        int v = nums[idx];
        if (freq[v-k] == 0 && freq[v+k] == 0) {
            freq[v]++;
            count += backtrack(nums, k, idx + 1);
            freq[v]--;
        }
        return count;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        return backtrack(nums, k, 0) - 1;
    }
};
