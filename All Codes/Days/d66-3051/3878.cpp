// Link: https://leetcode.com/problems/count-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: We can use a monotonic stack to find the nearest greater element to the left and right for each element in the array. We initialize two vectors l and r to store the indices of the nearest greater elements to the left and right, respectively. We iterate through the array from left to right to fill the l vector and from right to left to fill the r vector. For each element, we calculate the number of subarrays in which it is the maximum by multiplying the number of elements to the left and right of it that are less than it. Finally, we sum up the counts for all elements to get the total number of good subarrays.
class Solution
{
public:
    long long countGoodSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> l(n, -1), r(n, n);
        vector<int> stk;

        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            while (!stk.empty() && nums[stk.back()] < x && (nums[stk.back()] | x) == x)
            {
                stk.pop_back();
            }
            l[i] = stk.empty() ? -1 : stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && (nums[stk.back()] | nums[i]) == nums[i])
            {
                stk.pop_back();
            }
            r[i] = stk.empty() ? n : stk.back();
            stk.push_back(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans += (long long)(i - l[i]) * (r[i] - i);
        return ans;
    }
};
