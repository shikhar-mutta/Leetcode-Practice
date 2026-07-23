// Link: https://leetcode.com/problems/shortest-bridge/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), where n is the number of rows or columns in the grid.
// SC: O(n^2), where n is the number of rows or columns in the grid.
// Approach:
// 1. We will use DFS to find the first island and mark it as 2.
// 2. We will then use BFS to find the shortest path from the first island to the second island
// 3. We will return the length of the shortest path.
// Note: We will use a queue to perform BFS and a vector to store the directions of the 4 possible moves.

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef long long int lli;
#define pdi pair<double, int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tii tuple<int, int, int>
#define nl "\n"

const int MOD = 1000000007;

class Solution
{
public:
    const vector<int> dirs = {-1, 0, 1, 0, -1};

    int shortestBridge(vector<vector<int>> &a)
    {
        int n = a.size();
        int m = a[0].size();

        queue<pii> q;

        function<void(int, int)> dfs = [&](int i, int j)
        {
            a[i][j] = 2;
            q.emplace(i, j);
            for (int k = 0; k < 4; k++)
            {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1)
                {
                    dfs(x, y);
                }
            }
        };

        for (int i = 0, x = 1; i < n && x; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j])
                {
                    dfs(i, j);
                    x = 0;
                    break;
                }
            }
        }

        int ans = 0;
        while (1)
        {
            for (int h = (int)q.size(); h; h--)
            {
                auto it = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = it.first + dirs[k];
                    int y = it.second + dirs[k + 1];
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        if (a[x][y] == 1)
                        {
                            return ans;
                        }
                        if (a[x][y] == 0)
                        {
                            a[x][y] = 2;
                            q.emplace(x, y);
                        }
                    }
                }
            }
            ans++;
        }

        return ans;
    }
};

#ifdef LOCAL
int main()
{
    // freopen("inputSuvam.in", "r", stdin);
    // freopen("outputSuvam.out", "w", stdout);
    cout << "Compiled!" << nl;
    return 0;
}
#endif