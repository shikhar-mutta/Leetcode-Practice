// Link: https://leetcode.com/problems/russian-doll-envelopes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn).
    // SC: O(n).
    //  Approach:
    //  1. We can use a dynamic programming approach to solve this problem. We first sort the envelopes based on their width in ascending order. If two envelopes have the same width, we sort them based on their height in descending order. This ensures that we do not consider envelopes with the same width and different heights as valid candidates for nesting.
    //  2. After sorting, we can extract the heights of the envelopes and find the length of the longest increasing subsequence (LIS) of the heights. The length of the LIS will give us the maximum number of envelopes that can be nested inside each other.
    //  3. We can use a binary search approach to find the position of each height in the LIS. We maintain a vector to store the current LIS and update it as we iterate through the heights. If the current height is greater than the last element in the  LIS, we append it to the LIS. Otherwise, we replace the first element in the LIS that is greater than or equal to the current height with the current height. This ensures that we maintain the longest increasing subsequence at all times.
    //  4. Finally, we return the length of the LIS as the maximum number of envelopes that can be nested inside each other.
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {envelopes[i][0], -envelopes[i][1]};
        sort(a.begin(), a.end());
        vector<int> h(n);
        for (int i = 0; i < n; i++)
        {
            h[i] = -a[i].second;
        }
        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            int j = lower_bound(b.begin(), b.end(), h[i]) - b.begin();
            if (j >= b.size())
            {
                b.push_back(h[i]);
            }
            else
            {
                b[j] = h[i];
            }
        }
        return b.size();
    }
};