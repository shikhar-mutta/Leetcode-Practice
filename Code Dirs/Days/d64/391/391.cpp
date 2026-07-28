// Link: https://leetcode.com/problems/perfect-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: compute the total area of all rectangles and the bounding box, and check that the four corners of the bounding box are the only corners that appear an odd number of times (i.e. appear in the xor of all corners). If both conditions are satisfied, then the rectangles form a perfect rectangle.
const int N2 = 1e5 + 5;
inline uint64_t h(uint64_t z)
{
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
    z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
    return z ^ (z >> 31);
}
inline uint64_t idx(int64_t y, int64_t x)
{
    return ((y + N2) << 20) | x + N2;
}
class Solution
{
public:
    bool isRectangleCover(const vector<vector<int>> &rectangles)
    {
        int mn = INT_MAX, mx = INT_MIN;
        int mn2 = INT_MAX, mx2 = INT_MIN;
        uint64_t hs = 0;
        uint64_t area = 0;
        for (const auto &vc : rectangles)
        {
            area += 1ULL * (vc[2] - vc[0]) * (vc[3] - vc[1]);
            mn = min(mn, vc[0]);
            mx = max(mx, vc[2]);
            mn2 = min(mn2, vc[1]);
            mx2 = max(mx2, vc[3]);
            hs ^=
                h(idx(vc[0], vc[1])) ^
                h(idx(vc[0], vc[3])) ^
                h(idx(vc[2], vc[1])) ^
                h(idx(vc[2], vc[3]));
        }
        return area == 1ULL * (mx - mn) * (mx2 - mn2) && hs == (h(idx(mn, mn2)) ^
                                                                h(idx(mn, mx2)) ^
                                                                h(idx(mx, mn2)) ^
                                                                h(idx(mx, mx2)));
    }
};