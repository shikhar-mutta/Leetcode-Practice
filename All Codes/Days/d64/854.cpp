// Link: https://leetcode.com/problems/k-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * n! ) worst case, pruned heavily in practice  SC: O(states)
//  Approach: BFS where each state is a permutation of s1. To generate
//  successors of a state, find its first mismatched position i (relative
//  to s2), then swap s2[i] into any later position j where it fixes a
//  mismatch (state[j]==s2[i]) — this greedy restriction (only ever fix
//  the leftmost mismatch) avoids exploring the full swap space while
//  still reaching the optimum.
class Solution
{
    int ans;
    void dfs(string &s1, string &s2, int i, int cnt)
    {
        while (i < (int)s1.size() && s1[i] == s2[i])
            i++;
        if (i == (int)s1.size())
        {
            ans = min(ans, cnt);
            return;
        }

        // count remaining mismatches for lower-bound pruning
        int m = 0;
        for (int t = i; t < (int)s1.size(); t++)
            if (s1[t] != s2[t])
                m++;
        int lowerBound = cnt + (m + 1) / 2; // ceil(m/2)
        if (lowerBound >= ans)
            return;

        // pass 1: double-fix swaps (try first for early good answers)
        bool foundDouble = false;
        for (int j = i + 1; j < (int)s1.size(); j++)
        {
            if (s1[j] == s2[i] && s2[j] == s1[i])
            {
                swap(s1[i], s1[j]);
                dfs(s1, s2, i + 1, cnt + 1);
                swap(s1[i], s1[j]);
                foundDouble = true;
            }
        }
        if (foundDouble)
            return; // optional: double-fix is always optimal locally, safe to
                    // stop here

        // pass 2: single-fix swaps
        for (int j = i + 1; j < (int)s1.size(); j++)
        {
            if (s1[j] == s2[i])
            {
                swap(s1[i], s1[j]);
                dfs(s1, s2, i + 1, cnt + 1);
                swap(s1[i], s1[j]);
            }
        }
    }

public:
    int kSimilarity(string s1, string s2)
    {
        ans = INT_MAX;
        dfs(s1, s2, 0, 0);
        return ans;
    }
};