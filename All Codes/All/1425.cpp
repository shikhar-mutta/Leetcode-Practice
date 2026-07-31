// Link: https://leetcode.com/problems/constrained-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k)  SC: O(n)
//  Approach: Keep track of the last index used in the current subsequence and the current sum. If the current index is within k of the last index, add the current value to the sum. If the current index is more than k away from the last index, find the best value within the last k indices to add to the sum. If the current sum becomes negative, reset the last index and current sum to the current index and value. Keep track of the maximum sum found so far.
class Solution
{
public:
    int constrainedSubsetSum(vector<int> &a, int k)
    {
        int out = *max_element(a.begin(), a.end());
        int n = a.size();
        int last = 0;
        int curr = 0;
        vector<int> used(n, -1);
        for (int i = 0; i < n; i++)
        {
            // cout << curr << " " << last << "\n";
            if (a[i] < 0)
                continue;
            if (i - last <= k)
            {
                last = i;
                curr += a[i];
                out = max(out, curr);
                continue;
            }
            while (i - last > k && curr >= 0)
            {
                // cout << "hi";
                int best = INT_MIN;
                int idx = -1;
                for (int j = last + 1; j <= min(i, last + k); j++)
                {
                    if (a[j] >= best)
                    {
                        idx = j;
                        best = a[j];
                    }
                }
                used[idx] = last;
                curr += best;
                last = idx;

                for (int j = idx - 1; idx - j <= k && j >= 0; j--)
                {
                    if (used[j] != -1 && idx - used[j] <= k && a[j] < 0)
                    {
                        curr -= a[j];
                        used[j] = -1;
                    }
                }
                // cout << curr << " " << last << "\n";
            }
            if (curr < 0)
            {
                last = i;
                curr = a[i];
            }
            else
            {
                last = i;
                curr += a[i];
            }
            out = max(out, curr);
        }
        return out;
    }
};