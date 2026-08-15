// Link: https://leetcode.com/problems/optimal-division/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: max value is achieved by dividing the first number by
// (all remaining numbers divided by each other), i.e. a/(b/c/d/...)
// which equals a*c*d.../b; parenthesize as nums[0]/(nums[1]/.../nums[n-1])
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return to_string(nums[0]);
        if (n == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);

        string res = to_string(nums[0]) + "/(" + to_string(nums[1]);
        for (int i = 2; i < n; i++) res += "/" + to_string(nums[i]);
        res += ")";
        return res;
    }
};
