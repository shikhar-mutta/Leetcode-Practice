// Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m)
// SC: O(n*m) for the value->index map
// Approach: map each value to its painting-order index in arr. A row/column
// is "complete" once all its cells are painted, i.e. once we've reached the
// LATEST (max) index among its cells' values. The answer is the minimum such
// max-index over all rows and all columns.
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int n = mat.size();    // number of rows
        int m = mat[0].size(); // number of columns

        vector<int> Hash(n * m + 1, -1); // value -> index mapping

        for (int i = 0; i < arr.size(); i++) {
            Hash[arr[i]] = i; // store the painting-order index of each value
        }
        int ans = INT_MAX; // final answer
        // check all rows
        for (int i = 0; i < n; i++) {
            int maxi = 0; // latest index in this row
            for (int j = 0; j < m; j++) {
                maxi =
                    max(maxi, Hash[mat[i][j]]); // get all of the  maximum index
            }
            ans = min(ans, maxi); // take minimum over rows
        }
        // check all columns
        for (int j = 0; j < m; j++) {
            int maxi = 0; // latest index in this column
            for (int i = 0; i < n; i++) {
                maxi =
                    max(maxi, Hash[mat[i][j]]); // get all of the maximum index
            }
            ans = min(ans, maxi); // take minimum over columns
        }

        return ans; // earliest complete row/column
    }
};
