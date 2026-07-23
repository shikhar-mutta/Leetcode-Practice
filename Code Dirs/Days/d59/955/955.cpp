// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m), where n is the number of strings and m is the length of each string.
    // SC: O(n), where n is the number of strings.
    // Approach:
    // 1. We will iterate through each column of the strings.
    // 2. For each column, we will check if it is sorted or not.
    // 3. If it is not sorted, we will delete that column and increment the deletions count.
    // 4. If it is sorted, we will mark the pairs of strings that are sorted and continue to the next column.
    // 5. Finally, we will return the number of deletions.
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int deletions = 0;

        for (int col = 0; col < m; col++)
        {
            bool needDelete = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col])
                {
                    needDelete = true;
                    break;
                }
            }
            if (needDelete)
            {
                deletions++;
                continue;
            }
            for (int i = 0; i < n - 1; i++)
                if (!sorted[i] && strs[i][col] < strs[i + 1][col])
                    sorted[i] = true;
        }
        return deletions;
    }
};
