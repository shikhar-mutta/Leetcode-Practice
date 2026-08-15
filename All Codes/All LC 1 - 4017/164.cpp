// Link: https://leetcode.com/problems/maximum-gap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach: We use the pigeonhole principle to find the maximum gap between the sorted elements .
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return 0;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx)
            return 0;

        // pigeonhole: answer >= ceil((mx-mn)/(n-1)), so gaps within a
        // bucket of that width never matter — only gaps across buckets do
        long long width = max(1LL, ((long long)mx - mn + n - 2) / (n - 1));
        int cnt = (int)(((long long)mx - mn) / width) + 1;
        vector<int> bmin(cnt, INT_MAX), bmax(cnt, INT_MIN);
        for (int x : nums)
        {
            int b = (int)((x - (long long)mn) / width);
            bmin[b] = min(bmin[b], x);
            bmax[b] = max(bmax[b], x);
        }

        int ans = 0, prev = mn;
        for (int b = 0; b < cnt; b++)
        {
            if (bmin[b] == INT_MAX)
                continue; // empty bucket
            ans = max(ans, bmin[b] - prev);
            prev = bmax[b];
        }
        return ans;
    }
};
