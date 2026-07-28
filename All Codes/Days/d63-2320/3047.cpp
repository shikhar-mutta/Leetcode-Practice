// Link: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(1)
// Approach: For every pair of rectangles, compute their overlap rectangle
// (max of bottom-lefts, min of top-rights); the fitting square's side is
// min(width, height). Prune early: skip a rectangle entirely if its own
// max possible square side already can't beat the current best `m`.
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& a,vector<vector<int>>& b) {
        int m=0;
        for(int i=0,n=a.size();i<n;++i) {
            if(min(b[i][0]-a[i][0],b[i][1]-a[i][1])<=m)
                continue;
            for(int j=i+1;j<n;++j) {
                if(min(b[j][0]-a[j][0],b[j][1]-a[j][1])<=m)
                    continue;
                int g=max(a[i][0],a[j][0]),h=min(b[i][0],b[j][0]);
                if(h<=g)
                    continue;
                int p=max(a[i][1],a[j][1]),q=min(b[i][1],b[j][1]);
                if(p>=q)
                    continue;
                m=max(m,min(h-g,q-p));
            }
        }
        return 1LL*m*m;
    }
};
