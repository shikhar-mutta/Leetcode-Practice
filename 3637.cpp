// Link: https://leetcode.com/problems/trionic-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {

        int n = nums.size(), i = 0, cnt = 3, dir = 1;
        if (n < 3)
            return false;

        while (i < n - 1 && cnt > 0)
        {
            if (dir == 1)
            {
                while (i < n - 1 && nums[i] < nums[i + 1])
                    i++;
                dir = dir * -1;
                cnt--;
            }
            else if (dir == -1)
            {
                while (i < n - 1 && nums[i] > nums[i + 1])
                    i++;
                dir = dir * -1;
                cnt--;
            }

            if (cnt == 0)
                break;
        }
        if (i == n - 1 && cnt == 0)
            return true;
        return false;
    };
};