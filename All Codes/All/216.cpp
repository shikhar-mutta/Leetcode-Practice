// Link: https://leetcode.com/problems/combination-sum-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^n), SC: O(n)
    void backtrack(int k, int n, vector<int> &subset, vector<vector<int>> &res, int start = 1)
    {
        if (subset.size() == k && accumulate(subset.begin(), subset.end(), 0) == n)
        {
            res.push_back(subset);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            subset.push_back(i);
            backtrack(k, n, subset, res, i + 1); // Recur with the next index
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> subset;
        int track = 0;
        backtrack(k, n, subset, res, 1);
        return res;
    }
};
