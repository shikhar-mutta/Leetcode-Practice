// Link: https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return (int)(sum % k);
    }
};
