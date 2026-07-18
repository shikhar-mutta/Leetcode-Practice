// Link: https://leetcode.com/problems/maximal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), SC: O(m)
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        vector<int> heights(matrix[0].size(), 0);
        int maxArea = 0;

        for (const auto &row : matrix)
        {
            for (int j = 0; j < row.size(); j++)
            {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
