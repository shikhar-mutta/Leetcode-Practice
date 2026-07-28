// Link: https://leetcode.com/problems/find-mirror-score-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: keep a stack of unused indices per letter. For each index i,
//  look up the stack for its mirror letter ('a'<->'z', 'b'<->'y', ...); if
//  non-empty, pop the closest previous unused occurrence, add the index
//  gap to the score, and consume both. Otherwise push i onto its own
//  letter's stack to be matched later.
class Solution
{
public:
    long long calculateScore(string s)
    {
        vector<vector<int>> seen(26);
        long long res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int a = s[i] - 'a';
            if (seen[25 - a].empty())
            {
                seen[a].push_back(i);
            }
            else
            {
                int j = seen[25 - a].back();
                seen[25 - a].pop_back();
                res += i - j;
            }
        }
        return res;
    }
};