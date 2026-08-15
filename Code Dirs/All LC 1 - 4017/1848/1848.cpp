// Link: https://leetcode.com/problems/minimum-distance-to-the-target-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int best = INT_MAX;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == target) best = min(best, abs(i - start));
        }
        return best;
    }
};
