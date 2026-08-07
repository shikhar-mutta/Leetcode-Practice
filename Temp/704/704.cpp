// Link: https://leetcode.com/problems/binary-search/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: standard binary search.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};
