// Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)
// SC: O(m*n) for the memo table (+ recursion stack)
// Approach: memoized DFS from every cell in column 0. From (x,y), try moving
// to the 3 reachable cells in column y+1 (up-right, right, down-right) whose
// value is strictly greater, taking the best 1+result of those. Base case:
// reaching the last column costs 0 further moves. Answer is the max starting
// result over all rows in column 0.
class Solution {
private:
    bool isSafe(int x, int y, int m, int n)
    {
        return (x>=0 && y>=0 && x<m && y<n);
    }
    vector<int> dx = {-1, 0, 1};
    vector<int> dp;
    int solveMem(int x, int y, int m, int n, vector<vector<int>> &grid)
    {
        if(y==n-1) return 0;
        if(dp[(x*n)+y] != -1) return dp[(x*n)+y];
        int maxi = 0;
        for(int i=0; i<3; i++)
        {
            int nx = x+dx[i];
            int ny = y+1;
            if(isSafe(nx, ny, m, n) && grid[nx][ny]>grid[x][y])
            {
                maxi = max(maxi, 1+solveMem(nx, ny, m, n, grid));
            }
        }
        return dp[(x*n)+y]=maxi;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int maxi=0;
        dp.assign(m*n, -1);
        for(int i=0; i<m; i++)
        {
            maxi = max(maxi, solveMem(i, 0, m, n, grid));
        }
        return maxi;
    }
};
