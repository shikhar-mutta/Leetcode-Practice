// Link: https://leetcode.com/problems/increasing-triplet-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track smallest and second-smallest seen so far; if a third
// value beats both, a triplet exists
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long first = LLONG_MAX, second = LLONG_MAX;
        for (int x : nums) {
            if (x <= first) first = x;
            else if (x <= second) second = x;
            else return true;
        }
        return false;
    }
};
