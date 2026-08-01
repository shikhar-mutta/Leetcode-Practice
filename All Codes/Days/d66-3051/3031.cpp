// Link: https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
//  Approach: KMP algorithm to find the longest prefix which is also a suffix. Then check if the length of the remaining string is divisible by k. If it is, return the number of operations needed to revert the word to its initial state. If not, return the number of operations needed to revert the entire word to its initial state.
class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.length();
        int lps[n];
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < n)
        {
            if (word[len] == word[i])
            {
                lps[i] = len + 1;
                len = lps[i];
                i++;
            }
            else if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                len = 0;
                i++;
            }
        }
        len = lps[n - 1];
        while (len != 0)
        {
            int i = n - len;
            ;
            if (i % k == 0)
                return i / k;
            len = lps[len - 1];
        }
        return (n + k - 1) / k;
    }
};
