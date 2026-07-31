// Link: https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: total = 2*sum(specials) + outlier, so for each value v treated
//  as the "sum" element, the outlier candidate is total - 2*v. Check that
//  candidate actually exists in the array (with a second occurrence if it
//  equals v itself), and take the max valid candidate over all v.
class Solution
{
public:
    int getLargestOutlier(vector<int> &nums)
    {
        int count[2001] = {};
        int unique[2001];
        int unCount = 0;
        int sum = 0;
        for (int num : nums)
        {
            if (count[num + 1000]++ == 0)
                unique[unCount++] = num;
        }
        for (int i = 0; i < unCount; i++)
            sum += unique[i] * count[unique[i] + 1000];
        int ret = -2000;
        for (int i = 0; i < unCount; i++)
        {
            int num = unique[i];
            int diff = (sum - (num << 1));
            if (diff < -1000 || diff > 1000)
                continue;

            if (diff == num)
            {
                if (count[diff + 1000] >= 2)
                    ret = max(ret, diff);
            }
            else if (count[diff + 1000] >= 1)
                ret = max(ret, diff);
        }

        return ret;
    }
};