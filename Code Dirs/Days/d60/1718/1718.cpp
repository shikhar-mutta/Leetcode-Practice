// Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the input number.
// SC: O(n) for storing the result and used arrays.
// Approach:
//  1. Use backtracking to construct the sequence.
//  2. Start from the first index and try to place the largest number possible at that index.
//  3. If the number is greater than 1, place it at the current index and the index that is distance away from the current index.
//  4. If the number is 1, place it at the current index.
//  5. If the placement is successful, move to the next index and repeat the process.
class Solution
{
public:
    vector<int> constructDistancedSequence(int n)
    {
        vector<int> res(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(res, used, 0, n);
        return res;
    }

private:
    bool backtrack(vector<int> &res, vector<bool> &used, int i, int n)
    {
        if (i == res.size())
            return true;
        if (res[i] != 0)
            return backtrack(res, used, i + 1, n);

        for (int v = n; v >= 1; --v)
        {
            if (used[v])
                continue;
            int j = (v == 1) ? i : i + v;
            if (j >= res.size() || res[j] != 0)
                continue;

            used[v] = true;
            res[i] = res[j] = v;
            if (backtrack(res, used, i + 1, n))
                return true;
            used[v] = false;
            res[i] = res[j] = 0;
        }
        return false;
    }
};