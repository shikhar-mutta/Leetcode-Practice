// Link: https://leetcode.com/problems/find-indices-of-stable-mountains/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(n).
    vector<int> stableMountains(vector<int> &height, int threshold)
    {
        vector<int> res;
        int n = height.size();
        for (int i = 1; i < n; i++)
        {
            if (height[i - 1] > threshold)
                res.push_back(i);
        }
        return res;
    }
};
