// Link: https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: use hash set to store reversed words and count pairs
    // TC: O(n * m). SC: O(n * m).
    int maximumNumberOfStringPairs(vector<string> &words)
    {
        int count = 0;
        unordered_set<string> seen;
        for (const string &word : words)
        {
            string reversedWord = word;
            reverse(reversedWord.begin(), reversedWord.end());
            if (seen.count(reversedWord))
                count++;
            else
                seen.insert(word);
        }
        return count;
    }
};
