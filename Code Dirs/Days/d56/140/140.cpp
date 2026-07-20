// Link: https://leetcode.com/problems/word-break-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) where n is the length of the string s. The dfs function explores all possible substrings of s, and for each substring, it checks if it exists in the dictionary. In the worst case, we may have to explore all possible substrings, leading to a cubic time complexity.
// SC: O(n^2) where n is the length of the string s. The memoization table stores the results of subproblems, and in the worst case, we may have to store results for all possible starting indices of the string s, leading to a quadratic space complexity.
// Approach:
// 1. We use a depth-first search (DFS) approach to explore all possible ways to break the string s into valid words from the wordDict.
// 2. We maintain a memoization table to store the results of subproblems, which helps avoid redundant computations and improves efficiency.
// 3. The dfs function takes the current starting index and recursively explores all possible substrings of s starting from that index. If a substring is found in the dictionary, we recursively call dfs for the remaining part of the string. The results are combined to form valid sentences, which are stored in the memoization table for future reference.
// 4. The wordBreak function initializes the dictionary and starts the DFS from the beginning of the string s, returning all valid sentences that can be formed.
class Solution
{
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string &s, int start)
    {
        if (memo.count(start))
            return memo[start];

        vector<string> res;

        if (start == s.size())
        {
            res.push_back("");
            return res;
        }

        for (int end = start + 1; end <= s.size(); end++)
        {
            string word = s.substr(start, end - start);

            if (dict.count(word))
            {
                vector<string> temp = dfs(s, end);

                for (string &str : temp)
                {
                    if (str.empty())
                        res.push_back(word);
                    else
                        res.push_back(word + " " + str);
                }
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);
    }
};