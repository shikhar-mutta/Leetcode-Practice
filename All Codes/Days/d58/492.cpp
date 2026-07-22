// Link: https://leetcode.com/problems/construct-the-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(sqrt(area))
    // SC: O(1)
    //  Approach:
    //  1. We start by calculating the square root of the area, which gives us the maximum possible width of the rectangle.
    //  2. We then iterate downwards from this maximum width, checking if the area is divisible by the current width. If it is, we have found a valid width and can calculate the corresponding length by dividing the area by the width.
    //  3. We return the length and width as a vector, ensuring that the length is greater than or equal to the width.
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(area);
        while (area % w != 0)
            w--;
        return {area / w, w};
    }
};