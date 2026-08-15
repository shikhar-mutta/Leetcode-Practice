// Link: https://leetcode.com/problems/valid-elements-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n)
    vector<int> findValidElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        if (n == 1)
            return {nums[0]};
        if (nums.empty())
            return ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n - 1; i++)
        {
            if (valid(i, nums))
            {
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n - 1]);
        return ans;
    }

private:
    bool valid(int idx, vector<int> &nums)
    {
        bool d = true;
        for (int i = 0; i < idx; i++)
        {
            if (nums[idx] <= nums[i])
            {
                d = false;
                break;
            }
        }
        bool d2 = true;
        int n = nums.size();
        for (int i = idx + 1; i < n; i++)
        {
            if (nums[idx] <= nums[i])
            {
                d2 = false;
                break;
            }
        }
        if (d == true)
            return d;
        else if (d2 == true)
            return d2;
        else
            return false;
    }
};