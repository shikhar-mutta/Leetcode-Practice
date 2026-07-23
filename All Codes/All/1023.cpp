// Link: https://leetcode.com/problems/camelcase-matching/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n*m) SC: O(1)
    // Approach: Two Pointers
    // 1. Use two pointers i and j to traverse the query and pattern strings respectively.
    // 2. If the characters at both pointers match, increment both pointers.
    // 3. If the character in the query is uppercase and does not match the pattern, return false.
    // 4. If the character in the query is lowercase and does not match the pattern, increment the query pointer.
    // 5. After traversing the query, check if the pattern pointer has reached the end of the pattern. If so, return true; otherwise, return false.
    bool isMatch(const string &query, const string &pattern)
    {
        int i = 0, j = 0;
        int n = query.size(), m = pattern.size();
        while (i < n)
        {
            if (j < m && query[i] == pattern[j])
            {
                i++;
                j++;
            }
            else if (isupper(query[i]))
                return false;
            else
                i++;
        }
        return j == m;
    }

    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> result;
        for (auto &q : queries)
            result.push_back(isMatch(q, pattern));
        return result;
    }
};
