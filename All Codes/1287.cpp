// Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size(), crt = n / 4, cnt = 0, pre = arr[0];
        for (auto it : arr)
        {
            if (pre == it)
            {
                cnt++;
                if (cnt > crt)
                    return it;
            }
            else
            {
                pre = it;
                cnt = 1;
            }
        }
        return -1;
    }
};
