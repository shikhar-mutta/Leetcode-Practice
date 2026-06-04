// Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int closestTarget(vector<string> &words, string target, int startIndex)
    {
        int n = words.size();
        int ans = INT_MAX;
        // Iterate through the words array to find the target string
        for (int i = 0; i < n; i++)
            if (words[i] == target)
            {
                int clockwiseDist = (i - startIndex + n) % n;
                int counterClockwiseDist = (startIndex - i + n) % n;
                ans = min(ans, min(clockwiseDist, counterClockwiseDist));
            }

        return ans == INT_MAX ? -1 : ans;
    }
};
