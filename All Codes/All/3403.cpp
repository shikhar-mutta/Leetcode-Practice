// Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: Use a two-pointer technique to find the lexicographically largest substring.
//  The idea is to maintain two pointers, i and j, where i points to the start of the current best substring and j points to the start of the next candidate substring. We compare characters at these positions and move the pointers accordingly to find the largest substring.
class Solution
{
public:
    string answerString(string word, int numFriends)
    {
        int i = 0, j = 1;
        int k = 0;
        if (numFriends == 1)
            return word;
        int n = word.size();
        while (j + k < n)
        {
            if (word[i + k] == word[j + k])
                k++;
            else if (word[i + k] > word[j + k])
            {
                j = j + k + 1;
                k = 0;
            }
            else
            {
                if (i + k >= j)
                {
                    i = i + k + 1;
                }
                else
                    i = j;
                j = i + 1;
                k = 0;
            }
        }
        string curr = word.substr(i);
        int m = curr.size();
        int total = n - m + 1;

        if (total >= numFriends)
            return curr;
        int rem = n - m;
        int req = (numFriends - 1 - rem);
        return curr.substr(0, m - req);
    }
};