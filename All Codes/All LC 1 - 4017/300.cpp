// Link: https://leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n) where n is the length of the input array nums. We iterate through the array once, and for each element, we perform a binary search on the tails vector, which takes O(log n) time.
    // SC: O(n) where n is the length of the input array nums. We store the tails of the increasing subsequences in a separate vector, which can have at most n elements
    // Approach:
    //  1. We can use a dynamic programming approach to solve this problem.
    //  2. We can maintain a vector tails where tails[i] is the smallest tail of all increasing subsequences of length i+1.
    //  3. For each element x in the input array nums, we can perform a binary search on the tails vector to find the first element that is greater than or equal to x. If such an element is found, we replace it with x. Otherwise, we append x to the tails vector.
    //  4. The length of the tails vector at the end will be the length of the longest increasing subsequence.
    //  5. Finally, we return the length of the tails vector.
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tails;
        for (int x : nums)
        {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end())
                tails.push_back(x);
            else
                *it = x;
        }
        return (int)tails.size();
    }
};
