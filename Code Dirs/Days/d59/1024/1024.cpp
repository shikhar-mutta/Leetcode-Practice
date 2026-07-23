// Link: https://leetcode.com/problems/video-stitching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(n)
    //  Approach: Greedy
    //  1. Create a vector maxReach of size time, initialized to 0.
    //  2. Iterate through the clips and update maxReach[clip[0]] to the maximum of its current value and clip[1].
    //  3. Initialize count, curEnd, and farthest to 0.
    //  4. Iterate through the time from 0 to time - 1:
    //     a. Update farthest to the maximum of its current value and maxReach[i].
    //     b. If i equals curEnd, check if farthest is less than or equal to curEnd. If so, return -1 (not possible to cover the entire interval).
    //     c. Update curEnd to farthest and increment count.
    //  5. Return count as the minimum number of clips needed to cover the entire interval [0, time].
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        vector<int> maxReach(time, 0);
        for (auto &clip : clips)
        {
            if (clip[0] < time)
                maxReach[clip[0]] = max(maxReach[clip[0]], clip[1]);
        }

        int count = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < time; i++)
        {
            farthest = max(farthest, maxReach[i]);
            if (i == curEnd)
            {
                if (farthest <= curEnd)
                    return -1;
                curEnd = farthest;
                count++;
            }
        }
        return count;
    }
};
