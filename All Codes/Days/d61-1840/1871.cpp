// Link: https://leetcode.com/problems/jump-game-vii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string s
// SC: O(1)
//  Approach: Greedy
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        if (s[s.size() - 1] != '0')
            return 0;
        int minreach = 0, maxreach = 0, newmax = 0, newmin = INT_MAX;
        while (maxreach < s.size() - 1)
        {
            for (int i = minreach; i <= maxreach; i++)
            {
                if (s[i] == '0')
                {
                    newmin = min(newmin, i + minJump);
                    newmax = max(newmax, i + maxJump);
                }
            }
            if (newmax == maxreach)
                return 0;
            minreach = max(newmin, maxreach);
            maxreach = max(maxreach, newmax);
            newmin = INT_MAX;
        }
        if (minreach > s.size() - 1)
            return 0;
        return 1;
    }
};