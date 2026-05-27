// Link: https://leetcode.com/problems/remove-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != val)
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};