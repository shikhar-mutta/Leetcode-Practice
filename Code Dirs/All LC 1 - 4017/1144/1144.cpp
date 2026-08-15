// Link: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int moves[2] = {0, 0};
        for (int parity = 0; parity < 2; parity++) {
            for (int i = parity; i < n; i += 2) {
                int left = i > 0 ? nums[i-1] : INT_MAX;
                int right = i < n-1 ? nums[i+1] : INT_MAX;
                int limit = min(left, right);
                if (nums[i] >= limit) moves[parity] += nums[i] - limit + 1;
            }
        }
        return min(moves[0], moves[1]);
    }
};
