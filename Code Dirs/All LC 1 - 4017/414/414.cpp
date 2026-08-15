// Link: https://leetcode.com/problems/third-maximum-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track top 3 distinct values seen so far; fall back to max if
// fewer than 3 distinct values exist
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
        for (int x : nums) {
            if (x == first || x == second || x == third) continue;
            if (x > first) { third = second; second = first; first = x; }
            else if (x > second) { third = second; second = x; }
            else if (x > third) { third = x; }
        }
        return third == LLONG_MIN ? (int)first : (int)third;
    }
};
