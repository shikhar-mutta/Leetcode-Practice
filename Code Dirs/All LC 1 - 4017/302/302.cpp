// Link: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m log n + n log m)  SC: O(1)
// Approach: since all black pixels are connected, for each boundary do a
// binary search on rows/columns for the first/last row/col containing a '1'
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();

        auto rowHasBlack = [&](int r) {
            for (int c = 0; c < n; c++) if (image[r][c] == '1') return true;
            return false;
        };
        auto colHasBlack = [&](int c) {
            for (int r = 0; r < m; r++) if (image[r][c] == '1') return true;
            return false;
        };

        int top = 0, lo = 0, hi = x;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (rowHasBlack(mid)) hi = mid; else lo = mid + 1;
        }
        top = lo;

        lo = x; hi = m - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (rowHasBlack(mid)) lo = mid; else hi = mid - 1;
        }
        int bottom = lo;

        lo = 0; hi = y;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (colHasBlack(mid)) hi = mid; else lo = mid + 1;
        }
        int left = lo;

        lo = y; hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (colHasBlack(mid)) lo = mid; else hi = mid - 1;
        }
        int right = lo;

        return (bottom - top + 1) * (right - left + 1);
    }
};
