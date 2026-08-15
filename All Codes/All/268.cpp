// Link: https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: expected sum 0..n minus actual sum leaves the missing number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long expected = (long long)n * (n + 1) / 2;
        long long actual = 0;
        for (int x : nums) actual += x;
        return (int)(expected - actual);
    }
};
