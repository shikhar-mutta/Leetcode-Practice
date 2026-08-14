// Link: https://leetcode.com/problems/number-of-arithmetic-triplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        for (int x : nums) {
            if (s.count(x + diff) && s.count(x + 2 * diff)) count++;
        }
        return count;
    }
};
