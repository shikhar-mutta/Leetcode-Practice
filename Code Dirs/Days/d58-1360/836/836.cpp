// Link: https://leetcode.com/problems/rectangle-overlap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    //  Approach:
    //  1. To determine if two rectangles overlap, we can check if they do not overlap in either the x or y direction.
    //  2. If the right edge of one rectangle is to the left of the left edge of the other rectangle, or if the top edge of one rectangle is below the bottom edge of the other rectangle, then the rectangles do not overlap.
    //  3. If neither of these conditions is true, then the rectangles must overlap.
    //  4. We can use the min and max functions to find the edges of the rectangles and compare them.
    //  5. If the minimum of the right edges is greater than the maximum of the left edges, and the minimum of the top edges is greater than the maximum of the bottom edges, then the rectangles overlap.
    //  6. Return true if the rectangles overlap, and false otherwise.
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        bool xOverlap = min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]);
        bool yOverlap = min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
        return xOverlap && yOverlap;
    }
};
