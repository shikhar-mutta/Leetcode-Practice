// Link: https://leetcode.com/problems/find-closest-number-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int best = nums[0];
        for (int x : nums) {
            if (abs(x) < abs(best) || (abs(x) == abs(best) && x > best)) best = x;
        }
        return best;
    }
};
