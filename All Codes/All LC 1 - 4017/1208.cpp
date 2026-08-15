// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(1) as we are using a fixed number of variables to store the left and right pointers and the maxCost
    //  Approach:
    //  1. We will use a sliding window approach to find the maximum length of the substring of s that can be converted to t with a cost less than or equal to maxCost.
    //  2. We will maintain two pointers, left and right, to represent the current window of the substring of s that we are considering.
    //  3. We will iterate through the string s and for each character, we will calculate the cost of converting it to the corresponding character in t. We will subtract this cost from maxCost and check if it is still greater than or equal to 0. If it is, we will continue to expand the window by moving the right pointer to the right. If it is not, we will shrink the window by moving the left pointer to the right until the cost is less than or equal to maxCost again.
    //  4. We will keep track of the maximum length of the substring found so far and return it as the final result.
    int equalSubstring(string s, string t, int maxCost)
    {
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++)
        {
            maxCost -= abs(s[right] - t[right]);
            if (maxCost < 0)
            {
                maxCost += abs(s[left] - t[left]);
                left++;
            }
        }
        return s.size() - left;
    }
};