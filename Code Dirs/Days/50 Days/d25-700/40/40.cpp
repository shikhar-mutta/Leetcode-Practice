// Link: https://leetcode.com/problems/combination-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(2^N) . SC: O(N)
    void backTrack(vector<vector<int>> &res, vector<int> &candidates, int target, int ind, vector<int> &current)
    {
        if (target == 0) // Early Stop
        {
            res.push_back(current);
            return;
        }
        // candidates sorted: once one overshoots, all later ones do too.
        if (ind == (int)candidates.size() || candidates[ind] > target)
            return;

        // take the current index
        current.push_back(candidates[ind]);
        backTrack(res, candidates, target - candidates[ind], ind + 1, current);
        current.pop_back();

        // don't take it: skip ALL duplicates of candidates[ind] so we never
        // build the same combination twice (this is the key pruning step).
        int next = ind + 1;
        while (next < (int)candidates.size() && candidates[next] == candidates[ind])
            next++;
        backTrack(res, candidates, target, next, current);
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end()); // so each combination is built in sorted order
        vector<vector<int>> res;
        vector<int> current;
        backTrack(res, candidates, target, 0, current);
        return res;
    }
};
