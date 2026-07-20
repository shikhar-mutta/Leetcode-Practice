// Link: https://leetcode.com/problems/unique-binary-search-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) - We have two nested loops, where the outer loop runs n times and the inner loop runs up to n times in the worst case. Therefore, the overall time complexity is O(n^2).
    // SC: O(n) - We use a 1D DP array of size (n+1) to store the number of unique BSTs for each value of n. Therefore, the space complexity is O(n).
    // Approach:
    //  1. We initialize a DP array of size (n+1) with all values set to 0. We set dp[0] to 1, as there is one unique BST that can be formed with 0 nodes (the empty tree).
    //  2. We iterate through all values of i from 1 to n, representing the number of nodes in the BST.
    //  3. For each value of i, we iterate through all values of j from 0 to i-1, representing the number of nodes in the left subtree. The number of nodes in the right subtree is then i-1-j.
    //  4. We calculate the number of unique BSTs that can be formed with i nodes by summing the products of the number of unique BSTs that can be formed with j nodes in the left subtree and the number of unique BSTs that can be formed with i-1-j nodes in the right subtree. We store this value in dp[i].
    //  5. Finally, we return dp[n], which contains the number of unique BSTs that can be formed with n nodes.
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += dp[j] * dp[i - 1 - j];
        return dp[n];
    }
};
