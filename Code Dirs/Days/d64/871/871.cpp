// Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: greedy with a max-heap. Drive as far as current fuel
// allows, pushing every station's fuel amount passed along the way
// into the heap; whenever current reach is insufficient to continue,
// "retroactively" refuel at the largest fuel amount seen so far (as if
// stopping there), incrementing the stop count, until reach >= target
// or the heap is empty (impossible).
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap;
        long long reach = startFuel;
        int stops = 0;
        int i = 0, n = stations.size();
        while (reach < target) {
            while (i < n && stations[i][0] <= reach) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            if (maxHeap.empty()) return -1;
            reach += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        return stops;
    }
};
