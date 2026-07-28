// Link: https://leetcode.com/problems/trapping-rain-water-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*log(m*n))  SC: O(m*n)
// Approach: Use a min-heap to keep track of the minimum height of the boundary. Start by adding all the boundary cells to the heap. Then, repeatedly extract the cell with the minimum height from the heap and check its neighbors. If a neighbor is lower than the current cell, it can trap water, and we add the difference to the total water trapped. We then add the neighbor to the heap with its height updated to be the maximum of its original height and the current cell's height. This process continues until all cells have been processed.
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        if (m <= 2)
            return 0;
        int n = heightMap[0].size();
        if (n <= 2)
            return 0;

        static int heapH[40001];
        static int heapX[40001];
        static int heapY[40001];
        static bool vis[201][201];

        memset(vis, 0, sizeof(vis));

        int sz = 0;

        for (int i = 0; i < m; ++i)
        {
            int h = heightMap[i][0];
            int j = sz++;
            while (j && heapH[(j - 1) >> 1] > h)
            {
                heapH[j] = heapH[(j - 1) >> 1];
                heapX[j] = heapX[(j - 1) >> 1];
                heapY[j] = heapY[(j - 1) >> 1];
                j = (j - 1) >> 1;
            }
            heapH[j] = h;
            heapX[j] = i;
            heapY[j] = 0;

            h = heightMap[i][n - 1];
            j = sz++;
            while (j && heapH[(j - 1) >> 1] > h)
            {
                heapH[j] = heapH[(j - 1) >> 1];
                heapX[j] = heapX[(j - 1) >> 1];
                heapY[j] = heapY[(j - 1) >> 1];
                j = (j - 1) >> 1;
            }
            heapH[j] = h;
            heapX[j] = i;
            heapY[j] = n - 1;

            vis[i][0] = vis[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j)
        {
            int h = heightMap[0][j];
            int k = sz++;
            while (k && heapH[(k - 1) >> 1] > h)
            {
                heapH[k] = heapH[(k - 1) >> 1];
                heapX[k] = heapX[(k - 1) >> 1];
                heapY[k] = heapY[(k - 1) >> 1];
                k = (k - 1) >> 1;
            }
            heapH[k] = h;
            heapX[k] = 0;
            heapY[k] = j;

            h = heightMap[m - 1][j];
            k = sz++;
            while (k && heapH[(k - 1) >> 1] > h)
            {
                heapH[k] = heapH[(k - 1) >> 1];
                heapX[k] = heapX[(k - 1) >> 1];
                heapY[k] = heapY[(k - 1) >> 1];
                k = (k - 1) >> 1;
            }
            heapH[k] = h;
            heapX[k] = m - 1;
            heapY[k] = j;

            vis[0][j] = vis[m - 1][j] = true;
        }

        int ans = 0;

        while (sz)
        {
            int h = heapH[0], x = heapX[0], y = heapY[0];
            int vh = heapH[--sz];
            int vx = heapX[sz];
            int vy = heapY[sz];
            int i = 0;
            while (1)
            {
                int l = (i << 1) + 1;
                if (l >= sz)
                    break;
                int r = l + 1;
                int mn = (r < sz && heapH[r] < heapH[l]) ? r : l;
                if (vh <= heapH[mn])
                    break;
                heapH[i] = heapH[mn];
                heapX[i] = heapX[mn];
                heapY[i] = heapY[mn];
                i = mn;
            }
            heapH[i] = vh;
            heapX[i] = vx;
            heapY[i] = vy;

            int nx = x - 1, ny = y;
            if (nx >= 0 && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                int nh = heightMap[nx][ny];
                if (nh < h)
                    ans += h - nh, nh = h;
                int j = sz++;
                while (j && heapH[(j - 1) >> 1] > nh)
                {
                    heapH[j] = heapH[(j - 1) >> 1];
                    heapX[j] = heapX[(j - 1) >> 1];
                    heapY[j] = heapY[(j - 1) >> 1];
                    j = (j - 1) >> 1;
                }
                heapH[j] = nh;
                heapX[j] = nx;
                heapY[j] = ny;
            }
            nx = x + 1;
            ny = y;
            if (nx < m && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                int nh = heightMap[nx][ny];
                if (nh < h)
                    ans += h - nh, nh = h;
                int j = sz++;
                while (j && heapH[(j - 1) >> 1] > nh)
                {
                    heapH[j] = heapH[(j - 1) >> 1];
                    heapX[j] = heapX[(j - 1) >> 1];
                    heapY[j] = heapY[(j - 1) >> 1];
                    j = (j - 1) >> 1;
                }
                heapH[j] = nh;
                heapX[j] = nx;
                heapY[j] = ny;
            }
            nx = x;
            ny = y - 1;
            if (ny >= 0 && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                int nh = heightMap[nx][ny];
                if (nh < h)
                    ans += h - nh, nh = h;
                int j = sz++;
                while (j && heapH[(j - 1) >> 1] > nh)
                {
                    heapH[j] = heapH[(j - 1) >> 1];
                    heapX[j] = heapX[(j - 1) >> 1];
                    heapY[j] = heapY[(j - 1) >> 1];
                    j = (j - 1) >> 1;
                }
                heapH[j] = nh;
                heapX[j] = nx;
                heapY[j] = ny;
            }
            nx = x;
            ny = y + 1;
            if (ny < n && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                int nh = heightMap[nx][ny];
                if (nh < h)
                    ans += h - nh, nh = h;
                int j = sz++;
                while (j && heapH[(j - 1) >> 1] > nh)
                {
                    heapH[j] = heapH[(j - 1) >> 1];
                    heapX[j] = heapX[(j - 1) >> 1];
                    heapY[j] = heapY[(j - 1) >> 1];
                    j = (j - 1) >> 1;
                }
                heapH[j] = nh;
                heapX[j] = nx;
                heapY[j] = ny;
            }
        }
        return ans;
    }
};