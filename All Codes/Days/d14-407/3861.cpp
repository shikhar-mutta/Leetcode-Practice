// Link: https://leetcode.com/problems/minimum-capacity-box/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int minimumIndex(vector<int> &capacity, int itemSize)
    {
        int n = capacity.size(), waste = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++)
            if (capacity[i] - itemSize >= 0 && capacity[i] - itemSize < waste)
            {
                waste = capacity[i] - itemSize;
                ans = i;
            }
        return ans;
    }
};
