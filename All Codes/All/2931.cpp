// Link: https://leetcode.com/problems/maximum-spending-after-buying-items/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(1)
// Approach: We can use a greedy approach to find the maximum spending after buying items. We can iterate through the values array and for each item, we can find the minimum value among the last elements of each row. We can then add this minimum value multiplied by the current index to the answer and remove this minimum value from the corresponding row. We repeat this process until we have bought all items.
class Solution
{
public:
    long long maxSpending(vector<vector<int>> &values)
    {
        int m = values.size();
        int n = values[0].size();
        long long ans = 0;
        for (int i = 1; i <= m * n; i++)
        {
            int mini = INT_MAX;
            int idx = -1;
            for (int j = 0; j < m; j++)
            {
                if (values[j].size() > 0 && values[j].back() < mini)
                {
                    mini = values[j].back();
                    idx = j;
                }
            }
            ans += (long long)mini * i;
            values[idx].pop_back();
        }
        return ans;
    }
};
