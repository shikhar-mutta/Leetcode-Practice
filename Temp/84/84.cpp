// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: monotonic increasing stack of indices; when a shorter bar appears, pop and compute area
// using the popped bar's height with width spanning back to the new stack top
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int best = 0;
        int n = heights.size();
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
