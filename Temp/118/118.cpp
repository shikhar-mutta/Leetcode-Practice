// Link: https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(numRows^2)  SC: O(numRows^2)
// Approach: build each row from the previous, edges are 1, interior is the sum of the two above
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) row[j] = res[i-1][j-1] + res[i-1][j];
            res.push_back(row);
        }
        return res;
    }
};
