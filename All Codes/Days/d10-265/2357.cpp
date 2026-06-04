// Link: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: use Temp Vec. TC: O(N^2) SC: O(N)
    int minimumOperations(vector<int> &nums)
    {
        vector<int> temp;
        int cnt = 0;
        int mn = 0, tmn;
        while (nums.size() > 0)
        {
            temp.clear();
            tmn = INT_MAX;
            for (auto it : nums)
                if (it - mn > 0)
                {
                    temp.push_back(it - mn);
                    if (it - mn < tmn)
                        tmn = it - mn;
                }
            nums = temp;
            mn = tmn;
            cnt++;
        }
        return cnt - 1;
    }
};
