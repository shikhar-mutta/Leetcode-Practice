// Link: https://leetcode.com/problems/maximum-width-ramp/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach: Monotonic Stack
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;

        // 1. Tạo Monotonic Stack giảm dần lưu trữ các chỉ số i
        for (int i = 0; i < n; ++i)
        {
            if (st.empty() || nums[i] < nums[st.top()])
            {
                st.push(i);
            }
        }

        int max_width = 0;

        // 2. Duyệt từ phải sang trái để tìm j xa nhất cho từng i
        for (int j = n - 1; j >= 0; --j)
        {
            while (!st.empty() && nums[j] >= nums[st.top()])
            {
                max_width = max(max_width, j - st.top());
                st.pop(); // Loại bỏ chỉ số i đã tìm được j tối ưu nhất
            }
        }

        return max_width;
    }
};