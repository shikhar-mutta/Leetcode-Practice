// Link: https://leetcode.com/problems/132-pattern/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: scan right to left with a monotonic decreasing stack tracking
// candidate "3" values; pop smaller values into thirdMax (the best "2"
// candidate), if a later "1" is smaller than thirdMax, pattern found
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        long long thirdMax = LLONG_MIN;
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            if (nums[i] < thirdMax) return true;
            while (!stk.empty() && stk.top() < nums[i]) {
                thirdMax = stk.top();
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
