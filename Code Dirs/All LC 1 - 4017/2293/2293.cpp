// Link: https://leetcode.com/problems/min-max-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while (nums.size() > 1) {
            int n = nums.size();
            vector<int> next(n / 2);
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) next[i] = min(nums[2*i], nums[2*i+1]);
                else next[i] = max(nums[2*i], nums[2*i+1]);
            }
            nums = next;
        }
        return nums[0];
    }
};
