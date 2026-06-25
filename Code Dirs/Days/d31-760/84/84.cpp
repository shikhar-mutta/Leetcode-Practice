// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size(), best = 0;
        stack<int> st; // indices of increasing bar heights
        for (int i = 0; i <= n; i++)
        {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= h)
            {
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                best = max(best, height * (i - left - 1));
            }
            st.push(i);
        }
        return best;
    }
};
