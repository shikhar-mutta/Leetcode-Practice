// Link: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * log(max(nums[i]))), SC: O(n)
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
            {
                ans.push_back(-1);
                continue;
            }
            int k = 1, n1 = nums[i];
            while (nums[i])
            {
                if (n1 % 2)
                    k *= 2;
                else
                    break;
                n1 /= 2;
            }
            ans.push_back(nums[i] - k / 2);
        }
        return ans;
    }
};