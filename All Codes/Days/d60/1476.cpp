// Link: https://leetcode.com/problems/subrectangle-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach:
//   1. Store the original rectangle in a member variable rec.
//   2. Maintain a vector of mutations, where each mutation is represented as a tuple containing the coordinates of the subrectangle and the new value.
//   3. When updateSubrectangle is called, add the mutation to the mutations vector.
//   4. When getValue is called, iterate through the mutations vector in reverse order to find the most recent mutation that affects the specified cell. If a mutation is found, return the new value; otherwise, return the original value from rec.
// 5. This approach allows for efficient updates and queries, as the mutations are stored separately and only checked when needed.
class SubrectangleQueries
{

private:
    vector<vector<int>> rec;
    vector<tuple<int, int, int, int, int>> mutations;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        swap(rec, rectangle);
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2,
                            int newValue)
    {
        mutations.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col)
    {
        // reverse iter
        for (int i = mutations.size() - 1; i >= 0; i--)
        {
            auto [row1, col1, row2, col2, newValue] = mutations[i];
            if (row >= row1 && col >= col1 && row <= row2 && col <= col2)
            {
                return newValue;
            }
        }
        return rec[row][col];
    }
};
