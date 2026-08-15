// Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (int x : nums) if (x < k) cnt++;
        return cnt;
    }
};
