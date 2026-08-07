// Link: https://leetcode.com/problems/patching-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m + log n)  SC: O(1)
// Approach: greedily maintain reach = max value coverable so far ([1,reach]);
// if next num <= reach+1 extend reach by it, else patch with reach+1 (doubling reach)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long reach = 0;
        int patches = 0, i = 0;
        while (reach < n) {
            if (i < (int)nums.size() && nums[i] <= reach + 1) {
                reach += nums[i];
                i++;
            } else {
                reach += reach + 1;
                patches++;
            }
        }
        return patches;
    }
};
