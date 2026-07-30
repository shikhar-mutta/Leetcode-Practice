// Link: https://leetcode.com/problems/find-the-string-with-lcp/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
//  Approach: We can use a greedy approach to solve this problem. We can keep track of the characters in the string and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence. We can also keep track of the prefix and suffix of t in s and then use a two pointer approach to find the minimum score of the subsequence.
class Solution
{
public:
    string findTheString(vector<vector<int>> &lcp)
    {
        int n = lcp.size();
        string s(n, 0);
        char c = 'a';

        for (int i = 0; i < n; ++i)
        {
            if (s[i])
                continue;
            if (c > 'z')
                return "";
            for (int j = i; j < n; ++j)
                if (lcp[i][j])
                    s[j] = c;
            ++c;
        }

        for (int i = n - 1; i >= 0; --i)
        {
            if (lcp[i][i] != n - i)
                return "";
            for (int j = n - 1; j > i; --j)
            {
                int x =
                    (s[i] == s[j]
                         ? 1 + (i + 1 < n && j + 1 < n ? lcp[i + 1][j + 1] : 0)
                         : 0);
                if (lcp[i][j] != x || lcp[j][i] != x)
                    return "";
            }
        }

        return s;
    }
};
