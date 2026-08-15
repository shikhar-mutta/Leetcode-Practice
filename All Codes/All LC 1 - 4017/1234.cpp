// Link: https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s. We are iterating through the string once to count the characters and then using a sliding window approach to find the minimum length substring to replace.
    // SC: O(1) as we are using a fixed size array of 128 to count the characters, which is independent of the input size.
    //   Approach:
    //   1. We will first count the occurrences of each character in the string s and store it in a count array.
    //   2. We will then use a sliding window approach to find the minimum length substring that can be replaced to make the string balanced. We will maintain two pointers, i and j, to represent the current window. We will move the right pointer j to the right until the substring from i to j contains all characters with counts less than or equal to n/4. We will then move the left pointer i to the right to try and minimize the length of the substring while still maintaining the condition that all characters have counts less than or equal to n/4.
    //   3. We will keep track of the minimum length of the substring found during the process and return it as the final result.
    int balancedString(string s)
    {
        const int n = s.length();
        const int k = n / 4;
        int ans = n;
        vector<int> count(128);

        for (const char c : s)
            ++count[c];

        for (int i = 0, j = 0; i < n; ++i)
        {
            --count[s[i]];
            while (j < n && count['Q'] <= k && count['W'] <= k &&
                   count['E'] <= k && count['R'] <= k)
            {
                ans = min(ans, i - j + 1);
                ++count[s[j]];
                ++j;
            }
        }

        return ans;
    }
};