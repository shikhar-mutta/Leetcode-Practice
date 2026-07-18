// Link: https://leetcode.com/problems/pascals-triangle-ii/description/

#include <bits/stdc++.h>
using namespace std;

// nCr = nC(r-1) × (n - r + 1) / r
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        long long cur = 1;
        ans.push_back(1);
        for (int r = 1; r <= rowIndex; r++)
        {
            cur = cur * (rowIndex - r + 1) / r;
            ans.push_back((int)cur);
        }
        return ans;
    }
};