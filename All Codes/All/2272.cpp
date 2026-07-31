// Link: https://leetcode.com/problems/substring-with-largest-variance/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: We can use a dynamic programming approach to solve this problem. We can create a 2D array cur where cur[i][j] represents the current count of character i and character j in the substring. We can also create a 2D array mx where mx[i][j] represents the maximum variance of character i and character j in the substring. We can iterate through the string and update the cur and mx arrays based on the current character. Finally, we can return the maximum variance found in the mx array.
class Solution
{
public:
    int largestVariance(string s)
    {
        static int cur[26][26]{};
        memset(cur, 0, sizeof(cur));
        static int mx[26][26]{};
        fill(&**mx, &**mx + 26 * 26, INT_MIN);
        int res{0};
        for (const char c : s)
        {
            const int d{c - 'a'};
            for (const int i : views::iota(0, 26))
            {
                if (i == d)
                    continue;
                ++cur[d][i];
                ++mx[d][i];
                res = max(res, mx[d][i]);
            }
            for (const int i : views::iota(0, 26))
            {
                if (i == d)
                    continue;
                mx[i][d] = cur[i][d] - 1;
                cur[i][d] = max(0, cur[i][d] - 1);
                res = max(res, mx[i][d]);
            }
        }
        return res;
    }
};