// Link: https://leetcode.com/problems/pascals-triangle-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rowIndex^2)  SC: O(rowIndex)
// Approach: build the row in place, updating right-to-left so each element still reads the previous row's value
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++)
            for (int j = i - 1; j > 0; j--)
                row[j] += row[j-1];
        return row;
    }
};
