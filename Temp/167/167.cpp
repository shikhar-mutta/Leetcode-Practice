// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two pointers from both ends of the sorted array, moving based on sum vs target
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            if (sum < target) l++;
            else r--;
        }
        return {};
    }
};
