// Link: https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n) SC: O(n)
//  Approach:
//   1. We will use a backtracking approach to generate all possible splits of the string.
//   2. We will maintain a set to keep track of the unique substrings we have seen so far.
//   3. For each split, we will check if the substring is already in the set. If it is, we will skip that split. If it is not, we will add it to the set and continue to the next split.
//   4. We will keep track of the maximum number of unique substrings we have seen so far and return that as the result.
//   5. We will also prune the search space by checking if the number of unique substrings we have seen so far plus the number of remaining characters in the string is less than or equal to the best result we have seen so far. If it is, we can skip that branch of the search.
class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> seen;
        best = 0;
        dfs(s, 0, seen);
        return best;
    }

private:
    int best;
    void dfs(const string &s, int start, unordered_set<string> &seen)
    {
        if (start == s.size())
        {
            best = max(best, (int)seen.size());
            return;
        }
        if (seen.size() + (s.size() - start) <= best)
            return; // prune
        for (int len = 1; start + len <= s.size(); ++len)
        {
            string sub = s.substr(start, len);
            if (seen.count(sub))
                continue;
            seen.insert(sub);
            dfs(s, start + len, seen);
            seen.erase(sub);
        }
    }
};
