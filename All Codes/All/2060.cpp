// Link: https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n * d)  SC: O(m * n * d)
//   Approach: Use DFS with memoization to explore all possible ways to match the two encoded strings. Keep track of the current indices in both strings and the difference in the number of characters represented by the digits in the strings. Use a bitset to mark visited states to avoid redundant computations.
class Solution
{
public:
    bool possiblyEquals(string s1, string s2)
    {
        const int m{static_cast<int>(s1.length())},
            n{static_cast<int>(s2.length())};
        static bitset<1999> vis[41][41]{};
        for (int i{0}; i <= m; ++i)
        {
            for (int j{0}; j <= n; ++j)
            {
                vis[i][j].reset();
            }
        }
        auto chk{[&](this auto &&chk, int i, int j, int dif) -> bool
                 {
                     if (i == m && j == n)
                         return dif == 0;
                     if (!vis[i][j][dif + 999])
                     {
                         vis[i][j][dif + 999] = true;
                         if (i < m && isdigit(s1[i]))
                         {
                             for (int x{0}; i < m && isdigit(s1[i]); ++i)
                             {
                                 x = x * 10 + s1[i] - '0';
                                 if (chk(i + 1, j, dif + x))
                                     return true;
                             }
                             return false;
                         }
                         if (j < n && isdigit(s2[j]))
                         {
                             for (int x{0}; j < n && isdigit(s2[j]); ++j)
                             {
                                 x = x * 10 + s2[j] - '0';
                                 if (chk(i, j + 1, dif - x))
                                     return true;
                             }
                             return false;
                         }
                         if (dif < 0)
                             return i < m && chk(i + 1, j, dif + 1);
                         if (dif > 0)
                             return j < n && chk(i, j + 1, dif - 1);
                         return i < m && j < n && s1[i] == s2[j] &&
                                chk(i + 1, j + 1, dif);
                     }
                     return false;
                 }};
        return chk(0, 0, 0);
    }
};