// Link: https://leetcode.com/problems/stone-game-vi/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the array
// SC: O(n) as we are using a vector of vectors to store the indices of the elements in the arrays a and b
// Approach:
//   1. We can create a vector of vectors to store the indices of the elements in the arrays a and b based on their sum.
//   2. We can then iterate through the vector of vectors in reverse order and keep track of the scores of Alice and Bob based on whose turn it is.
//   3. Finally, we can return 1 if Alice has a higher score, -1 if Bob has a higher score, and 0 if they have the same score.
class Solution
{
public:
    int stoneGameVI(vector<int> &a, vector<int> &b)
    {
        int m = a.size();
        vector<vector<int>> indices(201);
        for (int i = 0; i < m; ++i)
        {
            indices[a[i] + b[i]].push_back(i);
        }

        bool turn = true;
        int ta = 0, tb = 0;
        for (int i = 200; i >= 0; --i)
        {
            for (auto index : indices[i])
            {
                if (turn)
                {
                    ta += a[index];
                }
                else
                {
                    tb += b[index];
                }

                turn = !turn;
            }
        }

        if (ta > tb)
            return 1;
        else if (ta < tb)
            return -1;
        return 0;
    }
};
