// Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) where n is the input number. The recursive function explores all possible guesses and calculates the minimum cost for each range of numbers, resulting in a cubic time complexity.
// SC: O(n^2) where n is the input number. The memoization table (arr) stores the minimum cost for each range of numbers, resulting in a quadratic space complexity.
//  Approach:
//  1. We can use a recursive function to explore all possible guesses and calculate the minimum cost for each range of numbers. The function takes the left and right bounds of the range and the current minimum cost as parameters.
//  2. If the left and right bounds are equal, we return 0 since there is no cost to guess a single number.
//  3. If the minimum cost for the current range has already been calculated and stored in the memoization table, we return that value to avoid redundant calculations.
//  4. We calculate the minimum cost for the current range by considering the cost of guessing the left and right bounds, as well as all possible guesses in between. For each guess, we calculate the maximum cost of the two resulting ranges and add the cost of the guess itself. We update the minimum cost for the current range accordingly.
//  5. Finally, we store the minimum cost for the current range in the memoization table and return that value. This ensures that we do not recalculate the minimum cost for the same range in future recursive calls, improving the efficiency of the algorithm.
class Solution
{
public:
    inline static int arr[201][201] = {{0}};
    int getMoneyAmount(int n)
    {
        return helper(1, n, INT_MAX);
    }
    int helper(int lft, int rt, int m)
    {
        if (m < 0)
            return INT_MAX / 2;
        if (lft == rt)
            return 0;
        if (arr[lft][rt] == 0)
        {
            m = min(rt + helper(lft, rt - 1, m - rt), lft + helper(lft + 1, rt, m - lft));
            for (int i = lft + 1; i < rt; i++)
            {
                m = min(m, i + max(helper(lft, i - 1, m - i), helper(i + 1, rt, m - i)));
            }
            arr[lft][rt] = m;
        }
        return arr[lft][rt];
    }
};
