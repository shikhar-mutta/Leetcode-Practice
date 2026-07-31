// Link: https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can use a stack to keep track of the heights of the people in the queue. We can iterate through the heights from right to left and for each height, we can pop the elements from the stack until we find a height that is greater than or equal to the current height. The number of elements popped from the stack will be the number of people that can see the current person. We can then push the current height onto the stack and continue to the next height. Finally, we can return the result for each person in the queue.
class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> s;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int count = 0;

            while (!s.empty() && heights[i] > s.top())
            {
                count++;
                s.pop();
            }
            if (!s.empty())
                count++;
            ans[i] = count;
            s.push(heights[i]);
        }
        return ans;
    }
};