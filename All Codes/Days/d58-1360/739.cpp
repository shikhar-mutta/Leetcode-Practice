// Link: https://leetcode.com/problems/daily-temperatures/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(n)
    //  Approach:
    //  1. We can use a stack to keep track of the indices of the temperatures.
    //  2. We will iterate through the temperatures array from the end to the beginning.
    //  3. For each temperature, we will pop the indices from the stack until we find a temperature that is greater than the current temperature.
    //  4. If the stack is empty, it means there is no warmer temperature in the future, so we will set the result for that day to 0. Otherwise, we will set the result for that day to the difference between the current index and the index of the next warmer temperature.
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;
        vector<int> res(n);
        res[n - 1] = 0;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                res[i] = 0;
            }
            else
            {
                res[i] = st.top() - i;
            }
            st.push(i);
        }
        return res;
    }
};