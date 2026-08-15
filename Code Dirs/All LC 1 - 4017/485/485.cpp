// Link: https://leetcode.com/problems/max-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track running streak of 1s, reset on 0
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int best = 0, cur = 0;
        for (int x : nums) {
            cur = x == 1 ? cur + 1 : 0;
            best = max(best, cur);
        }
        return best;
    }
};
