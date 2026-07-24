// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //   Approach:
    //   1. We can use a frequency array to count the occurrences of each character in both strings.
    //   2. For each character, we can calculate the difference in frequencies between the two strings.
    //   3. The sum of all positive differences will be the minimum number of steps required to make the strings anagrams.
    int minSteps(string s, string t)
    {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;
        for (char c : t)
            cnt[c - 'a']--;

        int ans = 0;
        for (int x : cnt)
            if (x > 0)
                ans += x;

        return ans;
    }
};