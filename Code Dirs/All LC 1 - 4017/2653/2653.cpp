// Link: https://leetcode.com/problems/sliding-subarray-beauty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> count(101, 0); // offset by 50, range -50..50
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            count[nums[i] + 50]++;
            if (i >= k) count[nums[i-k] + 50]--;
            if (i >= k - 1) {
                int remaining = x;
                int beauty = 0;
                for (int v = 0; v < 50; v++) {
                    remaining -= count[v];
                    if (remaining <= 0) { beauty = v - 50; break; }
                }
                ans.push_back(beauty);
            }
        }
        return ans;
    }
};
