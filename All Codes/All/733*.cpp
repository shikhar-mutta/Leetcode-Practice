// Link: https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int rows = image.size(), cols = image[0].size();
    int original = image[sr][sc];
    if (original == color) return image;  // avoid infinite loop if same color

    queue<pair<int, int>> qu;
    qu.push({sr, sc});
    image[sr][sc] = color;  // mark visited immediately

    vector<int> dr = {+1, -1, 0, 0};
    vector<int> dc = {0, 0, +1, -1};

    while (!qu.empty())
    {
        auto [r, c] = qu.front();
        qu.pop();  // FIX 1: pop the element
        for (int i = 0; i < 4; i++)
        {
            int rr = dr[i] + r;
            int cc = dc[i] + c;
            // FIX 2: correct bounds check using rows/cols
            if (rr >= 0 && rr < rows && cc >= 0 && cc < cols && image[rr][cc] == original)
            {
                image[rr][cc] = color;  // FIX 4: mark visited before pushing
                qu.push({rr, cc});
            }
        }
    }

    return image;
}

};
