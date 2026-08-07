// Link: https://leetcode.com/problems/maximum-product-of-three-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(1)
// Approach: sort; max product is either the three largest, or the two smallest (most negative) times the largest.
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long a = (long long)nums[n-1]*nums[n-2]*nums[n-3];
        long long b = (long long)nums[0]*nums[1]*nums[n-1];
        return (int)max(a, b);
    }
};
