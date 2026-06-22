// Link: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSplits(string s)
    {
        // and count where left distinct == right distinct.
        int n = s.size();
        int rightDistinct[n + 1];
        memset(rightDistinct, 0, sizeof(rightDistinct)); // init all to 0

        bitset<26> seen(0); // init all to 0
        int cnt = 0;
        // rightDistinct[i] = number of distinct characters in s[i..n-1]
        // prefix of rightDistinct is the suffix of s.
        for (int i = n - 1; i >= 0; --i)
        {
            if (!seen.test(s[i] - 'a'))
                seen.set(s[i] - 'a'), ++cnt;
            rightDistinct[i] = cnt;
        }

        bitset<26> seenL(0);
        int left = 0, ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (!seenL.test(s[i] - 'a'))
                seenL.set(s[i] - 'a'), ++left;

            if (left == rightDistinct[i + 1])
                ++ans;
        }
        return ans;
    }
};
