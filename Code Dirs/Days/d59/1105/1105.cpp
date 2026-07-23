// Link: https://leetcode.com/problems/filling-bookcase-shelves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the number of books
    // SC: O(n) where n is the number of books
    // Approach:
    //  1. We will use dynamic programming to solve this problem.
    //  2. We will create a dp array where dp[i] will store the minimum height of the bookshelf after placing the first i books.
    //  3. We will iterate through the books and for each book, we will try to place it on the current shelf or start a new shelf.
    //  4. We will keep track of the width and height of the current shelf and update the dp array accordingly.
    //  5. Finally, we will return dp[n] which will be the minimum height of the bookshelf after placing all the books.
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int width = 0, height = 0;
            for (int j = i; j >= 1; j--)
            {
                width += books[j - 1][0];
                if (width > shelfWidth)
                    break;
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + height);
            }
        }
        return dp[n];
    }
};
