// Link: https://leetcode.com/problems/shuffle-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach:
//   1. Store the original array in a member variable.
//   2. For the reset() function, simply return the original array.
//   3. For the shuffle() function, create a copy of the original array and shuffle it using the Fisher-Yates algorithm. This involves iterating from the end of the array to the beginning, and for each element, swapping it with a randomly chosen element from the unshuffled portion of the array. This ensures that each permutation of the array is equally likely.
//   4. Return the shuffled array.
class Solution
{
    vector<int> original;
    int n;

public:
    Solution(vector<int> &nums)
    {
        original = nums;
        n = original.size();
    }

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        // make a copy of the original
        vector<int> shuffled = original;

        int leftSize = n;
        for (int i = n - 1; i >= 0; i--)
        {
            // draw from the bag
            int j = rand() % leftSize;

            // put this element at current position
            // and put the original element in the bag
            swap(shuffled[i], shuffled[j]);
            leftSize--;
        }
        return shuffled;
    }
};