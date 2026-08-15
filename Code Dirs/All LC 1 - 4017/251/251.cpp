// Link: https://leetcode.com/problems/flatten-2d-vector/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per op  SC: O(1)
// Approach: track (row, col) pointers, advancing row past any empty inner vectors before each hasNext/next
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec) : data(vec), row(0), col(0) {}

    int next() {
        hasNext();
        return data[row][col++];
    }

    bool hasNext() {
        while (row < (int)data.size() && col == (int)data[row].size()) {
            row++;
            col = 0;
        }
        return row < (int)data.size();
    }

private:
    vector<vector<int>>& data;
    int row, col;
};
