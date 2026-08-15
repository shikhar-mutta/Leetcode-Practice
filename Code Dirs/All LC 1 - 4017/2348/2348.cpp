// Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0, run = 0;
        for (int x : nums) {
            if (x == 0) { run++; total += run; }
            else run = 0;
        }
        return total;
    }
};
