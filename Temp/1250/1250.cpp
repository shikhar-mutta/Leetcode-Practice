// Link: https://leetcode.com/problems/check-if-it-is-a-good-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for (int x : nums) g = __gcd(g, x);
        return g == 1;
    }
};
