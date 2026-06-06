// Link: https://leetcode.com/problems/ant-on-the-boundary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int returnToBoundaryCount(vector<int> &nums)
    {
        int count = 0, sum = 0;
        for (int x : nums)
        {
            sum += x;
            if (sum == 0)
                count++;
        }
        return count;
    }
};
