// Link: https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        int dropCount = 0, dropIdx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { dropCount++; dropIdx = i; }
        }
        if (dropCount == 0) return 0;
        if (dropCount > 1) return -1;
        return n - dropIdx - 1;
    }
};
