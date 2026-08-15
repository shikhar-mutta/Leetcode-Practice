// Link: https://leetcode.com/problems/majority-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, el1 = INT_MAX, el2 = INT_MAX;
        // Boyer-Moore Majority Vote Algorithm
        for (auto it : nums)
        {
            if (!cnt1 && el2 != it)
            {
                el1 = it;
                cnt1++;
            }
            else if (!cnt2 && el1 != it)
            {
                el2 = it;
                cnt2++;
            }
            else if (el1 == it)
            {
                cnt1++;
            }
            else if (el2 == it)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto it : nums)
        {
            if (it == el1)
                cnt1++;
            if (it == el2)
                cnt2++;
        }
        vector<int> result;
        int mini = (int)(n / 3) + 1;
        if (cnt1 >= mini)
        {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2)
        {
            result.push_back(el2);
        }
        return result;
    }
};