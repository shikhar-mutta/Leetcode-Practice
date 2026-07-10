// Link: https://leetcode.com/problems/car-fleet/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n) = O(nlogn)
// SC: O(n)
// Approach: Sort the cars based on their positions in descending order. Then, iterate through the sorted cars and calculate the time it takes for each car to reach the target. If the current car's time is greater than the maximum time seen so far, it forms a new fleet. Otherwise, it joins the existing fleet.

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx2")

static const int _ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

int speed_map[1000001];

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        if (n == 0)
            return 0;

        int min_pos = target, max_pos = 0;
        for (int i = 0; i < n; ++i)
        {
            speed_map[position[i]] = speed[i];
            if (position[i] < min_pos)
                min_pos = position[i];
            if (position[i] > max_pos)
                max_pos = position[i];
        }

        int fleets = 0;
        double max_time = -1.0;

        for (int i = max_pos; i >= min_pos; --i)
        {
            int s = speed_map[i];
            if (s > 0)
            {
                double current_time = (double)(target - i) / s;

                if (current_time > max_time)
                {
                    max_time = current_time;
                    fleets++;
                }
                speed_map[i] = 0;
            }
        }

        return fleets;
    }
};