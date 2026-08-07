// Link: https://leetcode.com/problems/jump-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: greedily track farthest reachable index; fail if current index ever exceeds it
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
