// Link: https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: count the number of distinct characters in the string.
//  The maximum number of substrings with distinct starting characters is equal to the number of distinct characters in the string.
//  For each distinct character, we can create a substring starting with that character, ensuring that the starting characters of the substrings are distinct.
class Solution
{
public:
    int maxDistinct(string s)
    {
        vector<int> vis(26, 0);
        int ans = 0;

        for (char c : s)
        {
            if (!vis[c - 'a'])
            {
                vis[c - 'a'] = 1;
                ans++;
            }
        }

        return ans;
    }
};