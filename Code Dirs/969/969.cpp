// Link: https://leetcode.com/problems/pancake-sorting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //TC: O(n^2) for finding the index of the maximum element in each iteration
    //SC: O(n) for storing the flips
    //Approach:
    // 1. Iterate from the largest element to the smallest element in the array.
    // 2. For each element, find its index in the current unsorted portion of the array.
    // 3. If the element is not already in its correct position, perform two flips:
    //    a. Flip the subarray from the start to the index of the element to bring it to the front.
    //    b. Flip the subarray from the start to the current size of the unsorted portion to move the element to its correct position.
    // 4. Store the flip sizes in a vector and return it after sorting the entire array.
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> flips;
        for (int k = n; k > 1; k--)
        {
            int idx = find(arr.begin(), arr.begin() + k, k) - arr.begin();
            if (idx == k - 1)
                continue;
            if (idx > 0)
            {
                flips.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
            flips.push_back(k);
            reverse(arr.begin(), arr.begin() + k);
        }
        return flips;
    }
};
