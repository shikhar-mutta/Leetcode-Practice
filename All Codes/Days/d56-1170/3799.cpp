// Link: https://leetcode.com/problems/word-squares-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^4)
    // SC: O(n^2)
    //  Approach:
    //  1. Sort the words in lexicographical order.
    //  2. Iterate through all possible combinations of four words and check if they form a valid word square.
    //  3. If they do, add them to the result vector.
    //  4. Return the result vector.
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        sort(words.begin(), words.end());
        int n = words.size();
        vector<vector<string>> res;
        for (int t = 0; t < n; t++)
            for (int l = 0; l < n; l++)
            {
                if (l == t || words[t][0] != words[l][0])
                    continue;
                for (int r = 0; r < n; r++)
                {
                    if (r == t || r == l || words[t][3] != words[r][0])
                        continue;
                    for (int b = 0; b < n; b++)
                    {
                        if (b == t || b == l || b == r)
                            continue;
                        if (words[b][0] == words[l][3] && words[b][3] == words[r][3])
                            res.push_back({words[t], words[l], words[r], words[b]});
                    }
                }
            }
        return res;
    }
};
