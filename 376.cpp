// Link: https://leetcode.com/problems/wiggle-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //  1. Initialize two variables up and down to 1, which will keep track of the length of the longest wiggle subsequence ending with an upward or downward trend, respectively.
    //  2. Iterate through the input array nums starting from the second element.
    //  3. For each element, compare it with the previous element:
    //     - If the current element is greater than the previous element, it indicates an upward trend, so we update the up variable to be down + 1.
    //     - If the current element is less than the previous element, it indicates a downward trend, so we update the down variable to be up + 1.
    //  4. Finally, return the maximum of up and down, which represents the length of the longest wiggle subsequence.
    
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int up = 1, down = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
                up = down + 1;
            else if (nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};
