// Link: https://leetcode.com/problems/stamping-the-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * (n-m))  n=|target|, m=|stamp|  SC: O(n)
//  Approach: reverse simulation. Repeatedly scan for a window in target
//  that could have been the last stamp applied — every character either
//  already matches stamp or is '?' (already turned into stamp by an
//  earlier reverse move), with at least one real (non-'?') match so we
//  make progress. Turn that whole window into '?', record its start
//  index, and repeat until everything is '?' (success) or no window
//  qualifies (impossible). Moves are recorded in reverse stamping order,
//  so the final answer is reversed.
class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int m = stamp.size();
        int n = target.size();
        vector<int> ans;
        vector<bool> visited(n, false);
        int stars = 0;
        while (stars < n)
        {
            bool replaced = false;
            for (int i = 0; i <= n - m; i++)
            {
                if (!visited[i] && canReplace(target, stamp, i))
                {
                    stars += doReplace(target, m, i);
                    visited[i] = true;
                    replaced = true;
                    ans.push_back(i);
                    if (stars == n)
                        break;
                }
            }
            if (!replaced)
                return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    bool canReplace(string &target, string &stamp, int pos)
    {
        for (int i = 0; i < stamp.size(); i++)
        {
            if (target[pos + i] != '?' && target[pos + i] != stamp[i])
                return false;
        }
        return true;
    }

    int doReplace(string &target, int len, int pos)
    {
        int count = 0;
        for (int i = 0; i < len; i++)
        {
            if (target[pos + i] != '?')
            {
                target[pos + i] = '?';
                count++;
            }
        }
        return count;
    }
};