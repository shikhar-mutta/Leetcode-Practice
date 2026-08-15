// Link: https://leetcode.com/problems/smallest-range-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        return max(0, hi - lo - 2 * k);
    }
};
