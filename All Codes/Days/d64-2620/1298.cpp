// Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2) worst case  SC: O(n)
// Approach: BFS-style processing with a queue of "have but not yet
// opened" boxes. Repeatedly scan the queue: if a box is open (or an
// earlier key unlocked it), collect its candy, add its keys (unlocking
// any already-held boxes) and its contained boxes to the pool, remove
// it, and restart the scan; loop until a full pass makes no progress.
class Solution
{
public:
    int maxCandies(vector<int> &status, vector<int> &candies, vector<vector<int>> &keys, vector<vector<int>> &containedBoxes, vector<int> &initialBoxes)
    {
        vector<bool> hasBox(status.size(), false);
        for (int b : initialBoxes)
            hasBox[b] = true;

        int total = 0;
        bool progress = true;
        while (progress)
        {
            progress = false;
            for (int b = 0; b < (int)status.size(); b++)
            {
                if (!hasBox[b] || status[b] != 1)
                    continue;
                hasBox[b] = false;
                total += candies[b];
                progress = true;
                for (int k : keys[b])
                    status[k] = 1;
                for (int cb : containedBoxes[b])
                    hasBox[cb] = true;
            }
        }
        return total;
    }
};
