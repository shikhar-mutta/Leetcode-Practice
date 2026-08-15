// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) SC: O(1)
// Approach: DFS to find the size of each island, if the size is divisible by k, increment the answer. Mark visited cells as 0 to avoid revisiting.
#define ll long long
class Solution
{
public:
    int n, m;
    int ans = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    ll f(vector<vector<int>> &a, int i, int j)
    {
        if (i < 0 or j < 0 or i == n or j == m or !a[i][j])
            return 0;

        ll val = a[i][j];
        a[i][j] = 0;

        for (int t = 0; t < 4; t++)
        {
            int r = i + dx[t];
            int c = j + dy[t];
            val += f(a, r, c);
        }

        return val;
    }
    int countIslands(vector<vector<int>> &a, int k)
    {

        n = a.size();
        m = a[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j])
                {
                    ll size = f(a, i, j);
                    if (size % k == 0)
                        ans++;
                }

        return ans;
    }
};