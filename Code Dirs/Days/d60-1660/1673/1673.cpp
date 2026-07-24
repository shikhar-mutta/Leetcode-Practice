// Link: https://leetcode.com/problems/find-the-most-competitive-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array.
    // SC: O(k) for storing the result.
    // Approach:
    //       1. Use a stack to keep track of the most competitive subsequence.
    //       2. Iterate through the input array and for each element, pop elements from the stack while the current element is smaller than the top of the stack and there are enough elements left in the array to fill the subsequence of length k.
    //       3. Push the current element onto the stack if the stack size is less than k.
    //       4. Return the elements in the stack as the result.
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int N = k;
        int st[N];
        int n = nums.size();
        int top = -1;
        for (int i = 0; i < n; i++)
        {
            while (top > -1 && st[top] > nums[i] && k - top <= n - i)
            {
                top--;
            }
            if (top < k - 1)
                st[++top] = nums[i];
        }
        return vector<int>(st, st + top + 1);
    }
};
