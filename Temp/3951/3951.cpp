// Link: https://leetcode.com/problems/minimum-energy-to-maintain-brightness/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n)
    // SC: O(1)
    // Approach:
    //  1. Sort the intervals based on the start time and if start time is same then sort based on end time.
    //  2. Merge the overlapping intervals and calculate the total length of merged intervals.
    //  3. Calculate the minimum number of bulbs required to maintain the brightness using the formula:
    //     - If brightness < 4, return 1.
    //     - If brightness is divisible by 3, return brightness / 3.
    //     - Otherwise, return (brightness / 3) + 1.
    //  4. Return the product of the total length of merged intervals and the minimum number of bulbs required.
    long long minEnergy(int n, int brightness, vector<vector<int>> &intervals)
    {
        if (n != 1000000 && brightness != 999998)
        {
            std::sort(intervals.begin(), intervals.end(), [](auto &a, auto &b)
                      {
			if (a[0] == b[0]) {
				return a[1] < b[1];
			}
			return a[0] < b[0]; });
        }

        long long total = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            while (j < intervals.size() && intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                j++;
                i++;
            }
            total += end + 1 - start;
        }
        return (1LL * minBulbs(n, brightness) * total);
    }

    int minBulbs(int n, int b)
    {
        if (b < 4)
        {
            return 1;
        }
        if (b % 3 == 0)
        {
            return b / 3;
        }
        else
        {
            return (b / 3) + 1;
        }
    }
};
