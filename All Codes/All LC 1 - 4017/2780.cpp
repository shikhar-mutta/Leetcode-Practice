// Link: https://leetcode.com/problems/minimum-index-of-a-valid-split/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //  1. Use the Boyer-Moore Voting Algorithm to find a candidate for the majority element in the array.
    //  2. Count the total occurrences of the candidate in the array.
    //  3. Iterate through the array and maintain a prefix count of the candidate.
    //  4. For each index, check if the prefix count of the candidate is greater than half of the left subarray length and if the remaining count of the candidate is greater than half of the right subarray length. If both conditions are satisfied, return the current index as the valid split index.
    //  5. If no valid split index is found, return -1.
    int minimumIndex(vector<int> &nums)
    {
        int candidate = 0;
        int balance = 0;

        for (int num : nums)
        {
            if (balance == 0)
                candidate = num;

            balance += (num == candidate) ? 1 : -1;
        }

        int total = 0;
        for (int num : nums)
        {
            if (num == candidate)
                total++;
        }

        int prefix = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == candidate)
                prefix++;

            int leftLen = i + 1;
            int rightLen = n - leftLen;

            if (prefix * 2 > leftLen && (total - prefix) * 2 > rightLen)
                return i;
        }

        return -1;
    }
};
