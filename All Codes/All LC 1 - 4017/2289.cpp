// Link: https://leetcode.com/problems/steps-to-make-array-non-decreasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int totalSteps(vector<int> &nums)
    {
        // Decreasing stack of {value, step at which it gets removed}.
        stack<pair<int, int>> st; // {num, steps}
        int res = 0;
        for (int num : nums)
        {
            int steps = 0;
            while (!st.empty() && st.top().first <= num)
            {
                steps = max(steps, st.top().second); // absorbs everything it deletes
                st.pop();
            }
            // empty -> nothing larger to the left, so num is never removed (0)
            steps = st.empty() ? 0 : steps + 1;
            res = max(res, steps);
            st.push({num, steps});
        }
        return res;
    }
};
