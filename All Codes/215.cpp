// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) on average, SC: O(1)
    // Approach: We use the quickselect algorithm to find the kth largest element in an unsorted array. The algorithm works by partitioning the array around a pivot element, such that all elements greater than the pivot are on the left and all elements less than the pivot are on the right.
    int findKthLargest(vector<int> &nums, int k)
    {
        // quickselect: partition so index k-1 holds the kth largest
        nth_element(nums.begin(), nums.begin() + (k - 1), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
