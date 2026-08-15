// Link: https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, cnt1 = 0, el, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (cnt == 0)
            {
                el = nums[i];
                cnt++;
            }
            else if (el == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        // check if the element is majority element or not
        for (int i = 0; i < n; i++)
        {
            if (el == nums[i])
                cnt1++;
        }
        // if the count of the element is greater than n/2 then return the element else return -1
        if (cnt1 > (n / 2))
            return el;
        else
            return -1;
    }
};