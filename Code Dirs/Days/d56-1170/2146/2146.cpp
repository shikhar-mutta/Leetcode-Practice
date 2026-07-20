// Link: https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(R*C*log(R*C)) where R is the number of rows and C is the number of columns in the grid.
    // SC: O(R*C) where R is the number of rows and C is the number of columns in the grid.
    // Approach:
    //  1. We will use a BFS to traverse the grid and find all the items within the price range.
    //  2. We will store the items in a vector of arrays where each array contains the distance from the start, the price of the item, and the coordinates of the item.
    //  3. We will sort the vector of arrays based on the distance, price, and coordinates of the items.
    //  4. We will return the first k items from the sorted vector of arrays.
    vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        int R = grid.size(), C = grid[0].size();
        int low = pricing[0], high = pricing[1];
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        queue<tuple<int, int, int>> q;
        q.push({start[0], start[1], 0});
        visited[start[0]][start[1]] = true;

        vector<array<int, 4>> candidates;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            auto [r, c, dist] = q.front();
            q.pop();
            int price = grid[r][c];
            if (price >= low && price <= high)
                candidates.push_back({dist, price, r, c});
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                    continue;
                if (visited[nr][nc] || grid[nr][nc] == 0)
                    continue;
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        for (int i = 0; i < (int)candidates.size() && i < k; i++)
            res.push_back({candidates[i][2], candidates[i][3]});
        return res;
    }
};
