// Link: https://leetcode.com/problems/transformed-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(n).
    vector<int> constructTransformedArray(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {

            if (nums[i] == 0)
            {
                result[i] = 0;
                continue;
            }
            result[i] = nums[((i + nums[i]) % n + n) % n];
        }

        return result;
    }
};