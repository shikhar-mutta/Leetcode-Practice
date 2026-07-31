// Link: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*26)  SC: O(26)
//  Approach: DP. Let dp[i][j] be the minimum distance to type the first i characters of the word, with the left finger on character j (or 26 if the left finger is not on any character). For each character in the word, we can either move the left finger to the current character or move the right finger to the current character. We update the dp array accordingly. The final answer is the minimum value in dp[n][j] for all j.
class Solution
{
    int dist(int a, int b)
    {
        int ax = a / 6, ay = a % 6, bx = b / 6, by = b % 6;
        return abs(ax - bx) + abs(ay - by);
    }

public:
    int minimumDistance(string word)
    {
        int n = word.size();
        if (n <= 1)
            return 0;
        vector<int> dp(27, INT_MAX);
        dp[26] = 0;

        for (int i = 1; i < n; i++)
        {
            int prev = word[i - 1] - 'A';
            int cur = word[i] - 'A';
            vector<int> ndp(27, INT_MAX);
            for (int idle = 0; idle < 27; idle++)
            {
                if (dp[idle] == INT_MAX)
                    continue;
                int costA = dist(prev, cur);
                ndp[idle] = min(ndp[idle], dp[idle] + costA);

                int costB = (idle == 26) ? 0 : dist(idle, cur);
                ndp[prev] = min(ndp[prev], dp[idle] + costB);
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
