// Link: https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, n);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            left[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.back()] >= nums[i]) stk.pop_back();
            right[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            long long length = right[i] - left[i] - 1;
            if ((long long)nums[i] * length > threshold) return (int)length;
        }
        return -1;
    }
};
