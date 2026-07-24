// Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //   1. If the length of the string is less than k, it's impossible to construct k palindrome strings, so we return false.
    //   2. We count the frequency of each character in the string using a vector of size 26 (for lowercase English letters).
    //   3. We then count how many characters have an odd frequency. This is because a palindrome can have at most one character with an odd frequency (which would be the middle character in the palindrome).
    //   4. If the number of characters with odd frequency is less than or equal to k, we can construct k palindrome strings, so we return true. Otherwise, we return false.
    //   5. The function returns true if it's possible to construct k palindrome strings, and false otherwise.
    bool canConstruct(string s, int k)
    {
        if (s.size() < k)
            return false;
        vector<int> cnt(26, 0);
        for (char c : s)
            ++cnt[c - 'a'];
        int odd = 0;
        for (int c : cnt)
            odd += c & 1;
        return odd <= k;
    }
};