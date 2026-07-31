// Link: https://leetcode.com/problems/trionic-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        while (p + 1 < n && nums[p+1] > nums[p]) p++;
        if (p == 0 || p >= n - 1) return false;

        int q = p;
        while (q + 1 < n && nums[q+1] < nums[q]) q++;
        if (q == p || q >= n - 1) return false;

        for (int i = q; i + 1 < n; i++) {
            if (nums[i+1] <= nums[i]) return false;
        }

        return true;
    }
};
