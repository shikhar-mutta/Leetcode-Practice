// Link: https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach:
//  1. We will create two arrays, pre and suf, to store the number of consecutive days before and after the current day where the security is non-increasing and non-decreasing respectively
//  2. We will iterate through the security array and fill the pre and suf arrays accordingly
//  3. Finally, we will iterate through the pre and suf arrays and check if the number of consecutive days before and after the current day is greater than or equal to time, if yes, we will add the current day to the answer vector
class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &security, int time)
    {
        int n = security.size();
        vector<int> pre(n, 0), suf(n, 0);
        pre[0] = 1;
        int c = 1;
        for (int i = 1; i < n; i++)
        {
            if (security[i] <= security[i - 1])
                c++;
            else
                c = 1;
            pre[i] = c;
        }
        suf[n - 1] = 1;
        c = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (security[i] <= security[i + 1])
                c++;
            else
                c = 1;
            suf[i] = c;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (pre[i] - 1 >= time && suf[i] - 1 >= time)
                ans.push_back(i);
        }
        return ans;
    }
};
