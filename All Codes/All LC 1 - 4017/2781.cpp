// Link: https://leetcode.com/problems/length-of-the-longest-valid-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the string, SC: O(n) where n is the length of the string
// Approach: We can use a sliding window approach to find the length of the longest valid substring. We will maintain a left bound and a right bound for the current substring. We will iterate through the string and for each character, we will check if the substring formed by the current character and the previous characters is valid or not. If it is valid, we will update the right bound and calculate the length of the current substring. If it is not valid, we will update the left bound to exclude the invalid substring and continue checking for valid substrings. Finally, we will return the maximum length of valid substrings found during the iteration.
using LL = long long;
class Solution
{
    unordered_set<LL> Set;
    unordered_map<int, vector<int>> Map;

public:
    int longestValidSubstring(string word, vector<string> &forbidden)
    {
        unordered_set<LL> forbiddenSet;
        for (const auto &s : forbidden)
        {
            LL code = 0;
            for (char ch : s)
            {
                code = (code << 5) + (ch - 'a' + 1);
            }
            forbiddenSet.insert(code);
        }
        int n = word.size();
        int leftBound = 0;
        int ans = 0;
        for (int right = 0; right < n; ++right)
        {
            LL currentCode = 0;
            for (int len = 1; len <= 10 && right - len + 1 >= leftBound;
                 ++len)
            {
                int left = right - len + 1;
                currentCode = currentCode +
                              ((LL)(word[left] - 'a' + 1) << (5 * (len - 1)));
                if (forbiddenSet.contains(currentCode))
                {
                    leftBound = left + 1;
                    break;
                }
            }
            ans = max(ans, right - leftBound + 1);
        }
        return ans;
    }

    void helper(string &word, int len)
    {
        int n = word.size();
        LL code = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= len)
                code &= (1LL << (5 * (len - 1))) - 1;
            code = (code << 5) + word[i] - 'a' + 1;
            if (i >= len - 1 && Set.find(code) != Set.end())
                Map[i - len + 1].push_back(i);
        }
    }
};