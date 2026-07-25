// Link: https://leetcode.com/problems/minimum-average-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: precompute the total sum, then sweep left to right maintaining
// a running left-side sum (LS) and derive the right-side sum as total-LS.
// For each split point i, compute floor(leftAvg) and floor(rightAvg)
// (rightAvg forced to 0 when the right side is empty, i.e. i is the last
// index), and track the index with the smallest absolute difference.
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        //Total Sum
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
        }

        long long LS = 0;
        long long RS = 0;

        int result = INT_MAX;
        int idx    = -1;

        for(int i = 0; i<n; i++) {
            LS += nums[i]; //nikalte chalenge
            RS  = sum-LS; //LS+RS = sum

            int n1 = i+1;
            int n2  = n-n1;

            long long left_avg  = LS/n1;
            long long right_avg = (i==n-1) ? 0 : RS/n2;

            int diff = abs(left_avg - right_avg);

            if(result > diff) {
                result = diff;
                idx = i;
            }
        }

        return idx;
    }
};
