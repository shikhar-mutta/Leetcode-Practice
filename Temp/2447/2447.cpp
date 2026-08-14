// Link: https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int g = 0;
            for (int j = i; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == k) count++;
            }
        }
        return count;
    }
};
