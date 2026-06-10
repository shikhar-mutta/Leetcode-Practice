// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long total = 1ll * m * k, n = bloomDay.size();

        if (total > n)
            return -1; // impossible
        // BS on Days
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int bouquets = 0, flowers = 0;
            bool canMake = false;
            // Can Make
            for (int d : bloomDay)
            {
                if (d <= mid)
                {
                    flowers++;
                    if (flowers == k)
                    {
                        bouquets++;
                        if (bouquets >= m)
                        {
                            canMake = true;
                            break;
                        }
                        flowers = 0;
                    }
                }
                else
                {
                    flowers = 0;
                }
            }
            // If can make then try smaller days else need more days
            if (canMake)
            {
                ans = mid;
                high = mid - 1; // try smaller days
            }
            else
            {
                low = mid + 1; // need more days
            }
        }
        return ans;
    }
};
