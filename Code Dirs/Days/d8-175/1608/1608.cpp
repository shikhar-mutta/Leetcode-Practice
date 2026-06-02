// Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size(), cnt;
        while (n > 0)
        {
            cnt = 0;
            for (auto it : nums)
                if (it >= n) // if elem is greater then or equal to n then we can count it
                    cnt++;
            if (cnt == n)
                return n;
            n--;
        }
        return -1;
    }
};
