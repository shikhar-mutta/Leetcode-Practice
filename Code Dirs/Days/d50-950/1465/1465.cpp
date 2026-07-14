// Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + M) where N is the number of horizontal cuts and M is the number of vertical cuts. The function findMaxGap runs in linear time relative to the number of cuts, and we call it twice (once for horizontal cuts and once for vertical cuts).
// SC: O(N + M) for storing the cuts in buckets. The space complexity is linear with respect to the number of cuts, as we create buckets to store the minimum and maximum values.
// Approach:
// 1. We define a helper function findMaxGap that takes the total size of the cake and a vector of cuts. This function calculates the maximum gap between consecutive cuts in linear time O(N).
// 2. Inside findMaxGap, we first find the absolute minimum and maximum among the cuts. We also consider virtual cuts at the boundaries (0 and totalSize) to account for the edges of the cake.
// 3. We calculate the bucket size and bucket count based on the range of cuts. We create two vectors, bucket_min and bucket_max, to store the minimum and maximum values for each bucket.
// 4. We distribute the cuts into the appropriate buckets based on their values. For each cut, we determine which bucket it belongs to and update the corresponding minimum and maximum values.
// 5. We then scan through the buckets to find the maximum gap between consecutive non-empty buckets. We keep track of the previous maximum value and calculate the gap between the current bucket's minimum and the previous maximum.

class Solution
{
private:
    // Helper function to find the maximum gap in linear time O(N)
    long long findMaxGap(int totalSize, vector<int> &cuts)
    {
        int n = cuts.size();
        if (n == 0)
            return totalSize;

        // Find the absolute min and max among the cuts
        int min_val = totalSize, max_val = 0;
        for (int cut : cuts)
        {
            min_val = min(min_val, cut);
            max_val = max(max_val, cut);
        }

        // We also consider virtual cuts at the boundaries: 0 and totalSize
        // Initial max gap candidates are the boundaries to the min/max elements
        long long max_gap = max(min_val, totalSize - max_val);

        // If all cuts are at the boundaries or identical, return early
        if (max_val == min_val)
            return max_gap;

        // Calculate bucket size and bucket count
        // There are n cuts, splitting the inside range into n-1 intervals
        double bucket_size = (double)(max_val - min_val) / (n + 1);
        if (bucket_size == 0)
            bucket_size = 1; // Prevent division by zero

        int bucket_count = n + 2;
        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);

        // Distribute cuts into buckets
        for (int cut : cuts)
        {
            int idx = (cut - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], cut);
            bucket_max[idx] = max(bucket_max[idx], cut);
        }

        // Scan buckets to find the maximum gap between consecutive non-empty
        // buckets
        int previous_max = max_val; // Start tracking from the boundaries
        // To accurately check internal gaps, we track from min_val onwards
        previous_max = min_val;

        for (int i = 0; i < bucket_count; i++)
        {
            if (bucket_min[i] == INT_MAX)
                continue; // Skip empty buckets

            // Gap between current bucket's min and previous bucket's max
            max_gap = max(max_gap, (long long)bucket_min[i] - previous_max);
            previous_max = bucket_max[i];
        }

        return max_gap;
    }

public:
    int maxArea(int h, int w, vector<int> &horizontalCuts,
                vector<int> &verticalCuts)
    {
        long long max_h_gap = findMaxGap(h, horizontalCuts);
        long long max_w_gap = findMaxGap(w, verticalCuts);

        int MOD = 1e9 + 7;
        return (max_h_gap * max_w_gap) % MOD;
    }
};