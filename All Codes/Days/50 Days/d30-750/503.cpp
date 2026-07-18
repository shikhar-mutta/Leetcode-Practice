// Link: https://leetcode.com/problems/next-greater-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> indices; // Stack to store indices of elements

        // Traverse the circular array twice to handle circularity
        for (int i = 0; i < 2 * n; ++i)
        {
            int current_num = nums[i % n];
            // While the current number is greater than the number at the top of the stack
            while (!indices.empty() && nums[indices.top()] < current_num)
            {
                result[indices.top()] = current_num;
                indices.pop();
            }
            // Only push indices from the first traversal to avoid duplicates
            if (i < n)
            {
                indices.push(i);
            }
        }

        return result;
    }
};