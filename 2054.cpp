// Link: https://leetcode.com/problems/two-best-non-overlapping-events/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of events.
// SC: O(n) where n is the number of events.
// Approach:
// 1. Create a vector of pairs to store the start time, end time, and value of each event.
// 2. Sort the events based on their start time.
// 3. Create a vector to store the maximum value of events that end before the start time of the current event.
// 4. Iterate through the events and for each event, find the maximum value of events that end before the start time of the current event using binary search.
// 5. Update the maximum value of events that end before the start time of the current event.
// 6. Return the maximum value of events that can be attended.

const int N = 2e5;
uint64_t Time[N];
class Solution
{
public:
    //    using info=tuple<int, bool, int>;
    static int maxTwoEvents(vector<vector<int>> &events)
    {
        const int n = events.size();
        for (int i = 0; i < n; i++)
        {
            int s = events[i][0], e = events[i][1], v = events[i][2];
            Time[2 * i] = ((uint64_t)s << 21) + v;
            Time[2 * i + 1] = ((uint64_t)e << 21) + (1 << 20) + v;
        }
        int n2 = n * 2;
        sort(Time, Time + (2 * n));
        int ans = 0, maxV = 0;
        for (int i = 0; i < n2; i++)
        {
            const auto info = Time[i];
            bool isEnd = (info >> 20) & 1;
            int v = info & ((1 << 20) - 1);
            if (isEnd)
                maxV = max(maxV, v);
            else
                ans = max(ans, maxV + v);
        }
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();