// Link: https://leetcode.com/problems/distinct-echo-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: For each starting index, use KMP to find all echo substrings starting at that index. Use a set to store distinct echo substrings.
//  An echo substring is a substring that can be written as A + A, where A is a non-empty string. For each starting index, we build the prefix function (KMP) for the substring starting at that index. Whenever we find a prefix that matches a suffix, we check if the total length of the substring is even and if it can be split into two equal halves. If so, we add it to the set of distinct echo substrings.
class Solution
{
public:
    int distinctEchoSubstrings(string text)
    {
        unordered_set<string> result;
        int len = text.size() - 1;
        int start = 0;
        while (start < len)
        {
            int subLen = KMP(text, start, result);
            if (subLen != INT_MAX)
            {
                len = min(len, subLen);
            }
            start++;
        }
        return result.size();
    }

    int KMP(string &text, int start, unordered_set<string> &result)
    {
        vector<int> prefix(text.size() - start, -1);
        int n = prefix.size();
        int lo = -1;
        for (int hi = 1; hi < n; ++hi)
        {
            while (lo > -1 && text[start + lo + 1] != text[start + hi])
            {
                lo = prefix[lo];
            }

            if (text[start + lo + 1] == text[start + hi])
            {
                lo++;
            }
            prefix[hi] = lo;

            if (lo + 1)
            {
                int totalLen = hi + 1;
                int subLen = hi - lo;
                if (totalLen % subLen == 0 && (totalLen / subLen) % 2 == 0)
                {
                    result.emplace(text.substr(start, totalLen));
                }
            }
        }
        if (prefix.back() + 1)
        {
            int totalLen = prefix.size();
            int subLen = prefix.size() - prefix.back() - 1;
            if (totalLen % subLen == 0)
            {
                return subLen;
            }
        }
        return INT_MAX;
    }
};