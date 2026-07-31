// Link: https://leetcode.com/problems/palindrome-partitioning-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
//   Approach: DP + Manacher's Algorithm
//    We can use Manacher's algorithm to find all the palindromic substrings in the string. We can use a 2D DP array to store the state of the game. The first dimension is the starting index of the substring, and the second dimension is the number of palindromic substrings we have found so far. We can use a recursive function to check if we can partition the string into 3 palindromic substrings. We can use memoization to store the results of the recursive function. We can use a helper function to check if a substring is a palindrome. We can use a helper function to get the new string with '$' characters inserted between each character. We can use a helper function to check if a substring is a palindrome using the Manacher's algorithm results. We can use a helper function to check if we can partition the string into 3 palindromic substrings using the DP array and the Manacher's algorithm results. We can use a helper function to check if we can partition the string into 3 palindromic substrings using the DP array and the Manacher's algorithm results. We can use a helper function to check if we can partition the string into 3 palindromic substrings.
class Solution
{
public:
    string getNewString(string &s)
    {
        string res = "";
        for (auto it : s)
        {
            res += '$';
            res += it;
        }
        res += '$';
        return res;
    }
    bool check(int i, int j, vector<int> &pal)
    {
        int len = j - i + 1;
        int ind = i + j + 1;
        return pal[ind] >= len;
    }
    int fn(int i, int k, string &s, vector<int> &pal, vector<vector<int>> &dp)
    {
        if (k == 1)
        {
            return check(i, s.size() - 1, pal);
        }
        if (i == s.size())
            return false;
        if (dp[i][k] != -1)
            return dp[i][k];
        bool res = false;
        for (int j = i; j < s.size() - 1; j++)
        {
            if (check(i, j, pal))
            {
                if (fn(j + 1, k - 1, s, pal, dp))
                {
                    res = true;
                    break;
                }
            }
        }
        return dp[i][k] = res;
    }
    bool checkPartitioning(string s)
    {
        string t = getNewString(s);
        int centre = 0, radius = 0;
        vector<int> P(t.size(), 0);
        for (int i = 0; i < t.size(); i++)
        {
            int mirror_i = 2 * centre - i;
            if (i < radius)
            {
                P[i] = min(radius - i, P[mirror_i]);
            }
            while ((i + P[i] + 1) < t.size() && (i - P[i] - 1) >= 0 &&
                   t[i + P[i] + 1] == t[i - P[i] - 1])
            {
                P[i]++;
            }
            if (i + P[i] > radius)
            {
                centre = i;
                radius = i + P[i];
            }
        }
        vector<vector<int>> dp(s.size(), vector<int>(4, -1));
        return (int)fn(0, 3, s, P, dp);
    }
};