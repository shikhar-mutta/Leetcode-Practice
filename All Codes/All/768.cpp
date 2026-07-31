// Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: compute prefix maximums. For each position, if the prefix maximum
//  is less than or equal to the suffix minimum, we can make a chunk here.
//  Count the number of such positions.
class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefmax;
        int mx = 0, ans = 0, mn = 2e9;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, arr[i]);
            prefmax.push_back(mx);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (prefmax[i] <= mn)
            {
                ans++;
            }
            mn = min(mn, arr[i]);
        }
        return ans;
    }
};