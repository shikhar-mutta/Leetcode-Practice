// Link: https://leetcode.com/problems/maximum-distance-in-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of arrays.
    // SC: O(1) as we are using constant space.
    //   Approach:
    //   1. The problem is to find the maximum distance between any two integers from different arrays.
    //   2. The solution iterates through the arrays, keeping track of the global maximum and minimum values seen so far.
    //   3. For each array, it calculates the distance between the local maximum and the global minimum, and the distance between the global maximum and the local minimum.
    //   4. It updates the maximum distance found so far and also updates the global maximum and minimum values for the next iteration.
    //  5. Finally, it returns the maximum distance found.
    int maxDistance(vector<vector<int>> &arrays)
    {
        int global_max = arrays[0].back();
        int global_min = arrays[0][0];
        int max_dist = 0;
        for (int i = 1; i < arrays.size(); i++)
        {
            int local_max = arrays[i].back();
            int local_min = arrays[i][0];
            max_dist = max(max_dist, abs(local_max - global_min));
            max_dist = max(max_dist, abs(global_max - local_min));

            global_max = max(local_max, global_max);
            global_min = min(global_min, local_min);
        }
        return max_dist;
    }
};