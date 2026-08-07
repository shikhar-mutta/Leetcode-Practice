// Link: https://leetcode.com/problems/contains-duplicate/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: insert into a hash set, comparing size before/after to detect a duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        return seen.size() != nums.size();
    }
};
