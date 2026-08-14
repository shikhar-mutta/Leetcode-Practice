// Link: https://leetcode.com/problems/happy-students/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWays(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;
        for (int c = 0; c <= n; c++) {
            bool ok = true;
            if (c > 0 && nums[c - 1] >= c) ok = false;
            if (c < n && nums[c] <= c) ok = false;
            if (ok) cnt++;
        }
        return cnt;
    }
};
