// Link: https://leetcode.com/problems/minimum-cost-for-cutting-cake-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m log m + n log n) where m is the length of horizontalCut and n is the length of verticalCut
    // SC: O(1) as we are using constant space
    //  Approach:
    //  1. We can sort the horizontalCut and verticalCut arrays in descending order
    //  2. We can then iterate through the horizontalCut and verticalCut arrays and at each step, we can choose the cut with the maximum cost and add it to the total cost.
    //  3. We can keep track of the number of horizontal and vertical pieces we have made so far and multiply the cost of the cut by the number of pieces we have made so far.
    //  4. We can continue this process until we have made all the cuts and return the total cost.
    //  5. Finally, we return the total cost of cutting the cake.
    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int i = 0, j = 0;
        int horizontalPieces = 1, verticalPieces = 1;
        int cost = 0;

        while (i < (int)horizontalCut.size() || j < (int)verticalCut.size())
        {
            if (j == (int)verticalCut.size() ||
                (i < (int)horizontalCut.size() && horizontalCut[i] >= verticalCut[j]))
            {
                cost += horizontalCut[i] * verticalPieces;
                horizontalPieces++;
                i++;
            }
            else
            {
                cost += verticalCut[j] * horizontalPieces;
                verticalPieces++;
                j++;
            }
        }

        return cost;
    }
};
