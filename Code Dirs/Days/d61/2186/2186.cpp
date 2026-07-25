// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//    Approach:
//    1. We can use a vector of size 26 to keep track of the count of each character in the first string and decrement the count for each character in the second string.
//    2. We can then iterate through the vector and sum the absolute values of the counts to get the minimum number of steps required to make the two strings anagrams of each other.
//    3. We can return the sum as the answer.
class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> cnt(26, 0);
        for (char c : s)
            ++cnt[c - 'a'];
        for (char c : t)
            --cnt[c - 'a'];
        int res = 0;
        for (int c : cnt)
            res += abs(c);
        return res;
    }
};