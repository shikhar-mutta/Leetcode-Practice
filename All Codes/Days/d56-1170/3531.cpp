// Link: https://leetcode.com/problems/count-covered-buildings/description/

#include <bits/stdc++.h>
using namespace std;

const int SZ = 100001;
int xMin[SZ], xMax[SZ], yMin[SZ], yMax[SZ];
class Solution
{
public:
    // TC: O(n) where n is the number of buildings
    // SC: O(n) where n is the number of buildings
    // Approach:
    //  1. We will use 4 arrays to store the minimum and maximum x and y coordinates for each y and x coordinate respectively.
    //  2. We will iterate through the buildings and update the minimum and maximum x and y coordinates for each y and x coordinate respectively.
    //  3. We will then iterate through the buildings again and check if the building is covered by checking if its x coordinate is between the minimum and maximum x coordinates for its y coordinate and if its y coordinate is between the minimum and maximum y coordinates for its x coordinate.
    //  4. If the building is covered, we will increment the count of covered buildings and return the count at the end.
    static int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        int M = 0, N = 0;
        for (auto &B : buildings)
        {
            const int x = B[0], y = B[1];
            M = max(x, M);
            N = max(y, N);
        }
        memset(xMax, 0, sizeof(int) * (N + 1));
        memset(yMax, 0, sizeof(int) * (M + 1));
        fill(xMin, xMin + (N + 1), INT_MAX);
        fill(yMin, yMin + (M + 1), INT_MAX);

        for (auto &B : buildings)
        {
            const int x = B[0], y = B[1];
            xMin[y] = min(xMin[y], x);
            xMax[y] = max(xMax[y], x);
            yMin[x] = min(yMin[x], y);
            yMax[x] = max(yMax[x], y);
        }
        int cnt = 0;
        for (auto &B : buildings)
        {
            const int x = B[0], y = B[1];
            const bool coverX = (xMin[y] < x & x < xMax[y]);
            const bool coverY = (yMin[x] < y & y < yMax[x]);
            cnt += (coverX & coverY);
        }
        return cnt;
    }
};
