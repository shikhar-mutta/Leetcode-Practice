// Link: https://leetcode.com/problems/combination-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^(t/m)). SC: O(t/m).
    void backTrack(vector<vector<int>> &res, vector<int> &candidates, int target, int ind, vector<int> &current)
    {
        if (target == 0) // Early Stop
        {
            res.push_back(current);
            return;
        }

        // Stop if we ran out of candidates or overshot the target.
        if (ind == (int)candidates.size() || target < 0)
            return;

        // Take candidates[ind] (stay at ind so it can be reused).
        current.push_back(candidates[ind]);
        backTrack(res, candidates, target - candidates[ind], ind, current);
        current.pop_back();

        // Not take: move past candidates[ind] permanently.
        backTrack(res, candidates, target, ind + 1, current);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        backTrack(res, candidates, target, 0, temp);
        return res;
    }
};
