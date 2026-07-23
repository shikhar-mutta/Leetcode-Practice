// Link: https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of columns in the colsum array
    // SC: O(1) as we are using a constant amount of extra space for the answer matrix
    //    Approach:
    //     1. We will create a 2D vector ans with 2 rows and n columns, initialized to 0.
    //     2. We will iterate through the colsum array
    //     3. If colsum[i] is 2, we will set ans[0][i] and ans[1][i] to 1, and decrement upper and lower by 1.
    //     4. If colsum[i] is 1, we will check if upper is greater than lower. If it is, we will set ans[0][i] to 1 and decrement upper by 1. Otherwise, we will set ans[1][i to 1 and decrement lower by 1.
    //     5. If at any point upper or lower becomes negative, we will return an empty vector as it is not possible to construct the matrix.
    //     6. After iterating through the colsum array, if upper or lower is not equal to 0, we will return an empty vector as it is not possible to construct the matrix.
    //     7. Finally, we will return the ans vector as the reconstructed matrix.
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int> &colsum)
    {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            if (colsum[i] == 2)
            {
                ans[0][i] = 1;
                ans[1][i] = 1;
                upper--;
                lower--;
            }
        }
        if (upper < 0 || lower < 0)
            return {};
        for (int i = 0; i < n; i++)
        {
            if (colsum[i] == 1)
            {

                if (upper > lower)
                {
                    ans[0][i] = 1;
                    upper--;
                }
                else
                {
                    ans[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper != 0 || lower != 0)
            return {};

        return ans;
    }
};