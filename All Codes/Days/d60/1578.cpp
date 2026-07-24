// Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach:
//  1. We will iterate through the colors string and for each group of consecutive same colors, we will calculate the total time needed to remove all but the most expensive balloon in that group.
//  2. We will keep track of the total time needed to remove the balloons and return that as the result.
//  3. We will use two pointers to keep track of the start and end of each group of consecutive same colors. The first pointer will point to the start of the group and the second pointer will point to the end of the group. We will calculate the total time needed to remove all but the most expensive balloon in that group by subtracting the maximum time from the total time of that group. We will then add that to our result and move the first pointer to the end of the group and repeat the process until we reach the end of the string.
//  4. Finally, we will return the total time needed to remove the balloons as the result.
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = 0, i = 0, n = colors.size();
        while (i < n)
        {
            int j = i, sum = 0, mx = 0;
            while (j < n && colors[j] == colors[i])
            {
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                ++j;
            }
            res += sum - mx;
            i = j;
        }
        return res;
    }
};