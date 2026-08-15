// Link: https://leetcode.com/problems/count-lattice-points-inside-a-circle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(201 * (circles + 202)) - for each of the 201 possible y values,
//     scan all circles plus a difference-array sweep over x
// SC: O(1) (fixed-size 202-slot difference array per row)
// Approach: coordinates are bounded (0-200 per constraints), so sweep every
// integer y from 0 to 200. For each circle whose vertical extent covers y,
// compute the horizontal half-width at that height via the circle equation
// and mark the covered x-range [x-halfwidth, x+halfwidth] in a difference
// array (increment at start, decrement just past the end) to merge
// overlapping circles for free. A running prefix sum over that difference
// array then tells, for each x, whether at least one circle covers (x,y);
// count every such covered point.
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& a) {
        int m=0;
        for(int y=0;y<201;++y) {
            int b[202]={0},k=0;
            for(int i=0,n=a.size();i<n;++i)
                if(a[i][1]-a[i][2]<=y&&y<=a[i][1]+a[i][2]) {
                    int x=sqrt(a[i][2]*a[i][2]-(y-a[i][1])*(y-a[i][1]));
                    ++b[a[i][0]-x],--b[a[i][0]+x+1];
                }
            for(int i=0;i<202;++i)
                if(k+=b[i],k>0)
                    ++m;
        }
        return m;
    }
};
