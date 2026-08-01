// Link: https://leetcode.com/problems/earliest-second-to-mark-indices-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(n + m)
//  Approach: Use a queue to keep track of the indices that need to be marked.
//  For each second, check if the index to be marked is already marked or not. If it is not marked, mark it and increment the count of marked indices. If it is already marked, check if there are any other indices that can be marked. If there are, mark one of them and increment the count of marked indices. If there are no other indices that can be marked, continue to the next second. If all indices are marked, return the current second. If all seconds are processed and not all indices are marked, return -1.
class Solution
{
public:
    int earliestSecondToMarkIndices(vector<int> &nums,
                                    vector<int> &changeIndices)
    {
        int n = nums.size(), m = changeIndices.size();
        if (m < n)
            return -1;

        int marked = 0;
        int zeros = count(nums.begin(), nums.end(), 0);

        vector<int> firstSecond(n, -1);
        for (int i = m - 1; i >= 0; i--)
            firstSecond[changeIndices[i] - 1] = i;

        queue<int> q;
        vector<int> emptySeconds(m, 0);
        for (int i = 0; i < n; i++)
        {
            if (firstSecond[i] == -1 && nums[i])
                q.push(i);
        }
        for (int i = m - 1; i >= 0; i--)
        {
            if (firstSecond[changeIndices[i] - 1] == i &&
                nums[changeIndices[i] - 1])
            {
                q.push(changeIndices[i] - 1);
            }
            else
                emptySeconds[i] = 1;
        }

        int x = 0;
        for (int i = 0; i < m; i++)
        {
            if (emptySeconds[i])
            {
                if (x)
                {
                    emptySeconds[i] = 0;
                    x--;
                }
            }
            else
                x++;
        }

        for (int i = 1; i < m; i++)
            emptySeconds[i] += emptySeconds[i - 1];

        for (int s = 0; s < m; s++)
        {
            if (nums[changeIndices[s] - 1])
            {
                nums[changeIndices[s] - 1] = 0;
                zeros++;
            }
            else if (zeros)
            {
                zeros--;
                marked++;
                if (marked == n)
                    return s + 1;
            }
            else
            {
                while (!q.empty() && ((firstSecond[q.front()] > -1 &&
                                       emptySeconds[firstSecond[q.front()]] -
                                               emptySeconds[s] + 1 <
                                           nums[q.front()]) ||
                                      !nums[q.front()]))
                {
                    q.pop();
                }
                if (!q.empty())
                {
                    nums[q.front()]--;
                    if (!nums[q.front()])
                    {
                        q.pop();
                        zeros++;
                    }
                }
            }
        }

        return -1;
    }
};
