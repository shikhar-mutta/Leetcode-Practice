// Link: https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return __gcd(mx, mn);
    }
};
