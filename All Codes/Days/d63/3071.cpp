// Link: https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(1) (bounded by 3 distinct values 0/1/2)
// Approach: Classify every cell as belonging to the Y-shape (both diagonals
// down to the center row, then the center column below it) or outside it,
// counting value frequencies per group. Try every ordered pair of distinct
// values (Y-value, out-value) and take the minimum total cells needing change.
class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        unordered_map<int,int>yvals;
        unordered_map<int,int>outvals;
        int n=grid.size();
        int mid=n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               bool isY =
    (i == j && i <= mid) ||
    (i + j == n - 1 && i <= mid) ||
    (j == mid && i >= mid);

                if(isY) yvals[grid[i][j]]++;
                else outvals[grid[i][j]]++;
            }


        }
        int totaly=0;
        for(auto x:yvals) totaly+=x.second;

        int tout=n*n - totaly;

        int mini=INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j) continue;
                mini=min(mini,(totaly-yvals[i])+(tout-outvals[j]));


            }
        }
        return mini;
            }
};
