// Link: https://leetcode.com/problems/minimum-number-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 1 < (int)nums.size(); i += 2) swap(nums[i], nums[i+1]);
        return nums;
    }
};
