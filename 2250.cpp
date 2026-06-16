// Link: https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/description/

#include <bits/stdc++.h>
using namespace std;

class Fenwick
{
    int n;
    vector<int> bit;

public:
    Fenwick(int n) : n(n)
    {
        bit.resize(n + 1);
    }

    void update(int idx, int val)
    {
        while (idx <= n)
        {
            bit[idx] += val;
            idx += idx & (-idx); // fetching the last set bit & adding it to the current index to get the next index to update
        }
    }

    int query(int idx)
    {
        int ans = 0;
        while (idx > 0)
        {
            ans += bit[idx];
            idx -= idx & (-idx);
        }
        return ans;
    }
};

// TC: O(nlogn + mlogm + (n+m)logk) where n = rectangles.size(), m = points.size(), k = max y coordinate
// SC: O(n + m + k) where n = rectangles.size(), m = points.size(), k = max y coordinate
// Fenwick tree + sorting  (Fenwick tree is used for prefixSum)
class Solution
{
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points)
    {
        // rectangle starting from 0,0 to l,h

        // y intentionally given small

        // point x,y inside a rectangle only if x <= l && y <= h (start pt is (0,0))

        // sort rectangles in decreasing order of x & same sort points in dec order

        // for a valid x we will need number of rectangles who have y <= h

        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b)
             { return a[0] > b[0]; }); // sort rectangles in decreasing order of x

        vector<array<int, 3>> pts; // {x, y, index}

        int n = points.size();
        for (int i = 0; i < n; i++)
            pts.push_back({points[i][0], points[i][1], i});

        sort(pts.begin(), pts.end(), [](auto &a, auto &b)
             { return a[0] > b[0]; }); // sort points in decreasing order of x

        Fenwick bit(100); // max y coordinate is 100

        vector<int> ans(points.size());

        int ptr = 0;

        // for every point we will add all the rectangles which satisfy the x coordinate condition and then query the fenwick tree to get the count of rectangles which satisfy the y coordinate condition
        for (auto &[x, y, i] : pts)
        {
            while (ptr < rectangles.size() && rectangles[ptr][0] >= x)
            { // for every x coordinate ok -> increase count of it's y coordinate by 1;
                bit.update(rectangles[ptr][1], 1);
                ptr++;
            }
            // now query the fenwick tree to get the count of rectangles which satisfy the y coordinate condition
            ans[i] = bit.query(100) - bit.query(y - 1);
        }

        return ans;
    }
};