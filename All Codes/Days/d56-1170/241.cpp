// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N^3) SC: O(N^2)
    //  Approach:
    //  1. We can use a recursive approach to solve this problem. We can iterate through the expression and whenever we encounter an operator, we can split the expression into two parts: the left part and the right part. We can then recursively call the function on both parts to get all the possible results for both parts. We can then combine the results from both parts using the operator to get all the possible results for the current expression. We can continue this process until we reach the base case where the expression is a single number. We can then return all the possible results for the current expression. We can use memoization to store the results for each sub-expression to avoid redundant calculations.
    //  2. We can use a hash map to store the results for each sub-expression. The key for the hash map can be a string representation of the sub-expression, and the value can be a vector of integers representing all the possible results for that sub-expression.
    unordered_map<string, vector<int>> dp;

    vector<int> solve(string &s, int l, int r)
    {

        string key = to_string(l) + "," + to_string(r);

        if (dp.count(key))
            return dp[key];

        vector<int> ans;

        bool isNumber = true;

        for (int i = l; i <= r; i++)
        {

            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {

                isNumber = false;

                vector<int> left = solve(s, l, i - 1);
                vector<int> right = solve(s, i + 1, r);

                for (int a : left)
                {
                    for (int b : right)
                    {

                        if (s[i] == '+')
                            ans.push_back(a + b);

                        else if (s[i] == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        if (isNumber)
        {
            ans.push_back(stoi(s.substr(l, r - l + 1)));
        }

        return dp[key] = ans;
    }

    vector<int> diffWaysToCompute(string expression)
    {

        return solve(expression, 0, expression.length() - 1);
    }
};