// Link: https://leetcode.com/problems/describe-the-painting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of segments. We iterate through the segments and add them to a map, which takes O(logn) time for each insertion. Then we iterate through the map to create the result, which takes O(n) time.
    // SC: O(n) where n is the number of segments. We use a map to store the difference of the segments, which takes O(n) space.
    // Approach:
    //  1. We use a difference map to keep track of the net change in color at each endpoint of the segments. For each segment [l, r, c], we add c to delta[l] and subtract c from delta[r]. This way, when we iterate through the map, we can calculate the total color at each point by adding the net change to a running sum.
    //  2. We iterate through the map and keep track of the previous endpoint and the running sum of colors. If the running sum is greater than 0, we add a new segment to the result with the previous endpoint, the current endpoint, and the running sum. We then update the running sum and the previous endpoint for the next iteration.
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        // difference map; touching delta[l] and delta[r] keeps every endpoint
        // as a key even when the net change is 0, forcing a split there
        map<int, long long> delta;
        for (auto &s : segments)
        {
            delta[s[0]] += s[2];
            delta[s[1]] -= s[2];
        }
        vector<vector<long long>> res;
        long long sum = 0;
        int prev = 0;
        for (auto &[x, d] : delta)
        {
            if (sum > 0)
                res.push_back({prev, x, sum});
            sum += d;
            prev = x;
        }
        return res;
    }
};
