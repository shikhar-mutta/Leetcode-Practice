// Link: https://leetcode.com/problems/find-latest-group-of-size-m/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();

        vector<int> len(n + 2, 0);

        int cnt = 0;
        int ans = -1;

        for (int step = 1; step <= n; step++)
        {
            int p = arr[step - 1];  // position turned on at this step
            int left = len[p - 1];  // size of group immediately to the left
            int right = len[p + 1]; // size of group immediately to the right
            int newLen = left + right + 1;

            // Set the new merged group's length at its two outer endpoints.
            len[p - left] = newLen;
            len[p + right] = newLen;

            // Maintain the count of size-m groups: the two neighbours (if any)
            // stop being separate groups; the merged group may become size m.
            if (left == m)
                cnt--;
            if (right == m)
                cnt--;
            if (newLen == m)
                cnt++;

            if (cnt > 0)
                ans = step; // a size-m group exists right now
        }

        return ans;
    }
};
