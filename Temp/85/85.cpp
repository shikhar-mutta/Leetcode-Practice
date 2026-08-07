// Link: https://leetcode.com/problems/maximal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(n)
// Approach: build a running histogram of consecutive '1' heights per column, apply the largest-rectangle-in-histogram
// monotonic stack algorithm on each row's histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int best = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            best = max(best, largestRectangleArea(heights));
        }
        return best;
    }
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int best = 0, n = heights.size();
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] >= h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                best = max(best, height * width);
            }
            st.push(i);
        }
        return best;
    }
};
