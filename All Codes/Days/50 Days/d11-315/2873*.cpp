// Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: use max_elem to find Max elem
    // Time Complexity: O(n^2) because of max_element function inside the loop
    long long maximumTripletValue(vector<int> &nums)
    {
        long long ans = 0, n = nums.size();
        // Iterate through the array from the second element to the second last element
        for (int i = 1; i < n - 1; i++)
        {
            // Find the maximum element to the left of the current element
            long long leftMax = *max_element(nums.begin(), nums.begin() + i);
            // Find the maximum element to the right of the current element
            long long rightMax = *max_element(nums.begin() + i + 1, nums.end());
            // Update the answer with the maximum value of the triplet (leftMax - nums[i]) * rightMax
            ans = max(ans, (leftMax - nums[i]) * rightMax);
        }
        return ans;
    }
};
