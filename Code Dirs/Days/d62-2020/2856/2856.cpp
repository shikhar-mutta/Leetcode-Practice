// Link: https://leetcode.com/problems/minimum-array-length-after-pair-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: nums is sorted, so pair up the first half against the second
// half (starting j at the midpoint, i at 0): if nums[i] < nums[j] they form a
// valid distinct-value pair (advance both), otherwise j alone advances
// looking for a bigger value to pair with i. Each successful pair removes 2
// elements; this greedily maximizes pair count since every value in the first
// half is <= every value it could try to pair with going forward.
class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=(n+1)/2;
        int pairs = 0;
        while(j<n){
            if(nums[i]<nums[j]){
                pairs++;
                i++;
                j++;
            }
            else j++;
        }
        return n - 2*pairs;
    }
};
