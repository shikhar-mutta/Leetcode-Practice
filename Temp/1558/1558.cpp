// Link: https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0, maxDoubles = 0;
        for (int x : nums) {
            int doublings = 0;
            while (x > 0) {
                if (x % 2 == 1) { ops++; x--; }
                else { x /= 2; doublings++; }
            }
            maxDoubles = max(maxDoubles, doublings);
        }
        return ops + maxDoubles;
    }
};
