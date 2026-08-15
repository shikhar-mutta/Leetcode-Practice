// Link: https://leetcode.com/problems/neither-minimum-nor-maximum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3) return -1;
        int mn = min({nums[0], nums[1], nums[2]});
        int mx = max({nums[0], nums[1], nums[2]});
        for (int x : {nums[0], nums[1], nums[2]})
            if (x != mn && x != mx) return x;
        return -1;
    }
};
