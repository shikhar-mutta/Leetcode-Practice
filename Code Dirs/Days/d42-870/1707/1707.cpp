// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + mlogm + m*logn). SC: O(n).
// Approach: We can sort the nums array and then for each query we can use binary search to find the maximum number in the nums array which is less than or equal to the second element of the query. Then we can use bit manipulation to find the maximum XOR of the first element of the query with the numbers in the range found by binary search. We can do this by iterating from the 29th bit to the 0th bit and checking if we can set that bit in the result. If we can set that bit, we update our range accordingly.
class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> v(n, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            if (nums[0] > queries[i][1])
            {
                v[i] = -1;
                continue;
            }
            auto it1 = nums.begin();
            auto it2 = upper_bound(nums.begin(), nums.end(), queries[i][1]);
            int x = queries[i][0], y = 0;
            for (int j = 29; j >= 0 && it2 - it1 > 1; j--)
            {
                if ((*(it2 - 1) & (1 << j)) == 0)
                    continue;
                if (*it1 & (1 << j))
                {
                    y |= (1 << j);
                    continue;
                }
                auto it3 = lower_bound(it1, it2, y | (1 << j));
                if (x & (1 << j))
                    it2 = it3;
                else
                {
                    y |= (1 << j);
                    it1 = it3;
                }
            }
            v[i] = *it1 ^ x;
        }
        return v;
    }
};