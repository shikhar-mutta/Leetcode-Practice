// Link: https://leetcode.com/problems/find-the-score-difference-in-a-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: simulate directly — track which player is active, applying
// a swap before scoring whenever nums[i] is odd or i is a (0-indexed)
// multiple-of-6 position (game index 5, 11, ...), then add the points to
// that player's total.
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int p1 = 0, p2 = 0;
        bool firstActive = true;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] % 2 != 0) firstActive = !firstActive;
            if (i % 6 == 5) firstActive = !firstActive;
            if (firstActive) p1 += nums[i];
            else p2 += nums[i];
        }
        return p1 - p2;
    }
};
