// Link: https://leetcode.com/problems/buddy-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool buddyStrings(string s, string goal)
    {
        int n = s.size(), m = goal.size();
        if (n != m)
            return false;

        vector<int> diff;
        for (int i = 0; i < n; i++) // find the indices where s and goal differ
            if (s[i] != goal[i])
                diff.push_back(i);

        if (diff.size() == 2) // if only 2 differ, check swap makes them equal
            return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];

        if (diff.size() == 0)
        {
            vector<int> freq(26, 0);
            for (char c : s)
                if (++freq[c - 'a'] >= 2)
                    return true;
            return false;
        }

        return false;
    }
};
