// Link: https://leetcode.com/problems/product-of-array-except-self/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra (excluding output)
// Approach: prefix-product pass left-to-right, then multiply in a running suffix-product right-to-left
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) res[i] = res[i-1] * nums[i-1];
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
};
