// Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log(max power)), SC: O(N)
// Approach: The problem is to maximize the minimum power of a city after adding k power stations. The solution involves using binary search to find the maximum minimum power that can be achieved. For each candidate minimum power, we simulate the process of adding power stations and check if it is possible to achieve that minimum power with the given number of additional stations. We use a difference array to efficiently manage the power distribution and keep track of the total power added. The binary search continues until we find the maximum minimum power that can be achieved.
class Solution
{
public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();

        static long long p[100005];
        static long long diff[100005];

        long long cur = 0;
        for (int i = 0; i < r && i < n; ++i)
            cur += stations[i];

        for (int i = 0; i < n; ++i)
        {
            if (i + r < n)
                cur += stations[i + r];
            if (i - r - 1 >= 0)
                cur -= stations[i - r - 1];
            p[i] = cur;
        }

        long long low = 0;
        long long high = *max_element(p, p + n) + k;
        long long ans = 0;

        int window_len = 2 * r + 1;

        while (low <= high)
        {
            long long mid = (low + high) >> 1;

            memset(diff, 0, sizeof(long long) * (n + 1));

            long long add_sum = 0, spent = 0;
            bool ok = true;

            for (int i = 0; i < n; ++i)
            {
                add_sum -= diff[i];

                long long total = p[i] + add_sum;

                if (total < mid)
                {
                    long long need = mid - total;
                    spent += need;

                    if (spent > k)
                    {
                        ok = false;
                        break;
                    }

                    add_sum += need;

                    int end = i + window_len;
                    if (end < n)
                        diff[end] += need;
                }
            }

            if (ok)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};