// Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: greedy with a max-heap. Drive as far as current fuel
//  allows, pushing every station's fuel amount passed along the way
//  into the heap; whenever current reach is insufficient to continue,
//  "retroactively" refuel at the largest fuel amount seen so far (as if
//  stopping there), incrementing the stop count, until reach >= target
//  or the heap is empty (impossible).
class Solution
{
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>> &stations)
    {

        priority_queue<int> pq;

        int curr = 0;
        int fuel = startFuel;
        int ans = 0;
        int idx = 0;

        while (curr + fuel < target)
        {

            while (idx < stations.size() && stations[idx][0] <= curr + fuel)
            {
                pq.push(stations[idx][1]);
                idx++;
            }
            curr = curr + fuel;
            fuel = 0;

            if (pq.empty())
                return -1;

            fuel += pq.top();
            pq.pop();
            ans++;
        }

        return ans;
    }
};