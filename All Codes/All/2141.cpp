// Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogm), SC: O(1)
//  Approach: The problem can be solved by using binary search to find the maximum running time of n computers. We can use a helper function to check if it is possible to run the computers for a given time. We can then use binary search to find the maximum running time.
class Solution
{
public:
    typedef long long ll;

    bool possible(vector<int> &batteries, int mid, int n)
    {
        long long target = 1LL * n * mid;
        for (int i = 0; i < batteries.size(); i++)
        {
            target -= min(mid, batteries[i]);
            if (target <= 0)
                return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int> &batteries)
    {
        ll l = *min_element(batteries.begin(), batteries.end());
        ll sum = 0;
        for (int &i : batteries)
        {
            sum += i;
        }
        ll r = sum / n;
        ll result = 0;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (possible(batteries, mid, n))
            {
                result = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return result;
    }
};
