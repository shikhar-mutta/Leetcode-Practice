// Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &colors)
    {
        int n = colors.size();
        int maxDist = 0;

        // Check from the leftmost and rightmost ends
        for (int i = 0; i < n; i++)
        {
            if (colors[i] != colors[0])
            {
                maxDist = max(maxDist, i); // Distance from the left end
            }
            if (colors[n - 1 - i] != colors[n - 1])
            {
                maxDist = max(maxDist, i); // Distance from the right end
            }
        }

        return maxDist;
    }
};
