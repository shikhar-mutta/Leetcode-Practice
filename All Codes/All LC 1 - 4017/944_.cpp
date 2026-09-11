// Link: https://leetcode.com/problems/delete-columns-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int count = 0;
        int n = strs.size();
        int m = strs[0].size();

        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                if (strs[i][j] < strs[i - 1][j])
                {
                    count++;
                    break; // No need to check further for this column
                }
            }
        }

        return count;
    }
};
