// Link: https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> allDistinct(nums.begin(), nums.end());
        int total = allDistinct.size();

        int count = 0;
        for (int left = 0; left < n; left++) {
            unordered_map<int,int> freq;
            int distinct = 0;
            for (int right = left; right < n; right++) {
                if (freq[nums[right]]++ == 0) distinct++;
                if (distinct == total) count++;
            }
        }
        return count;
    }
};
