// Link: https://leetcode.com/problems/valid-square/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: compute all 6 pairwise squared distances, sort them; a valid square has 4 equal smaller values (sides) and 2 equal larger values (diagonals = 2*side), with sides > 0.
class Solution {
    long long dist2(vector<int>& a, vector<int>& b) {
        long long dx = a[0]-b[0], dy = a[1]-b[1];
        return dx*dx + dy*dy;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> pts = {p1, p2, p3, p4};
        vector<long long> d;
        for (int i = 0; i < 4; i++)
            for (int j = i+1; j < 4; j++)
                d.push_back(dist2(pts[i], pts[j]));
        sort(d.begin(), d.end());
        if (d[0] == 0) return false;
        return d[0]==d[1] && d[1]==d[2] && d[2]==d[3] && d[4]==d[5] && d[4]==2*d[0];
    }
};
