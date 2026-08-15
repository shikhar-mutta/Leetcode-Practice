// Link: https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) average, O(n^2) worst case (rare)
    // SC: O(1)
    // Approach:
    //  1. If k=0, return n (all elements qualify)
    //  2. Use nth_element to find the kth largest element in the array.
    //  3. Count the number of elements that are strictly less than the kth largest element
    //  4. Return the count
    int countElements(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k == 0)
            return n; // "at least 0 greater" -> everything qualifies

        // place the kth-largest value at index n-k (smaller elements before it)
        nth_element(nums.begin(), nums.begin() + (n - k), nums.end());
        int threshold = nums[n - k]; // kth largest

        int count = 0;
        for (int x : nums)
            count += (x < threshold); // strictly-less are qualified
        return count;
    }
};
