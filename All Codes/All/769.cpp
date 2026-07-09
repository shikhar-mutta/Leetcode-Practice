// Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: Iterate through the array and keep track of the maximum value seen so far. If the maximum value is equal to the current index, it means we can make a chunk here and increment the chunk count. Finally, return the total number of chunks.
    int maxChunksToSorted(vector<int> &arr)
    {
        int chunks = 0, mx = 0;
        for (int i = 0; i < (int)arr.size(); i++)
        {
            mx = max(mx, arr[i]);
            if (mx == i)
                chunks++;
        }
        return chunks;
    }
};
