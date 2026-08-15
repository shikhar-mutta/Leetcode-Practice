// Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = n - 1, cnt = 0;
        while (l < r) {
            if (nums[l] + nums[r] < target) { cnt += r - l; l++; }
            else r--;
        }
        return cnt;
    }
};
