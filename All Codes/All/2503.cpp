// Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*M + KlogK), SC: O(N*M + K)
//  Approach: We can use a priority queue to keep track of the maximum value in the grid. We can also use a queue to keep track of the cells that we have already visited. We can start from the top-left cell and push it into the queue. We can then pop the cell from the queue and check its neighbors. If the neighbor is less than the current query value, we can push it into the queue and mark it as visited. We can also push the neighbor into the priority queue. We can then pop the maximum value from the priority queue and check if it is less than the current query value. If it is, we can increment the count of cells that are less than the current query value. We can repeat this process until we have processed all the queries. Finally, we can return the count of cells that are less than the current query value for each query.
class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size(), m = grid[0].size(), k = queries.size();
        vector<pair<int, int>> hash(k);
        vector<int> ans(k, 0), ansSort(k, 0);

        for (int i = 0; i < k; i++)
            hash[i] = {queries[i], i};
        sort(hash.begin(), hash.end());

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int r = 0;
        for (r = 0; r < k; r++)
        {
            if (grid[0][0] < hash[r].first)
            {
                break;
            }
        }

        queue<pair<int, int>> q;
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            s;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        if (r < k)
        {
            q.push({0, 0});
            vis[0][0] = 1;
            cnt = 1;
        }

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    if (grid[nx][ny] < hash[r].first)
                    {
                        cnt++;
                        q.push({nx, ny});
                    }
                    else
                    {
                        s.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }

            if (q.empty())
            {
                while (true)
                {
                    ansSort[r] = cnt;
                    r++;
                    if (r == k)
                        break;

                    while (!s.empty() && s.top().first < hash[r].first)
                    {
                        auto cur = s.top();
                        s.pop();

                        q.push({cur.second.first, cur.second.second});
                        cnt++;
                    }

                    if (!q.empty())
                        break;
                }

                if (r == k)
                    break;
            }
        }

        for (int i = 0; i < k; i++)
            ans[hash[i].second] = ansSort[i];

        return ans;
    }
};