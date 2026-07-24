// Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string.
    // SC: O(n) where n is the length of the string.
    // Approach:
    //   1. The total number of happy strings of length n is 3 * 2^(n-1). If k is greater than this total, return an empty string.
    //   2. The first character can be 'a', 'b', or 'c'. Each choice leads to 2^(n-1) happy strings. Determine the first character based on k.
    //   3. For the remaining characters, each character can be one of the two characters that are different from the previous character. Use the remaining value of k to determine the next character.
    //   4. Repeat this process until the string is fully constructed.
    string getHappyString(int n, int k)
    {
        long long total = 3LL * (1LL << (n - 1));
        if (k > total)
            return "";

        string res;
        long long block = 1LL << (n - 1);
        --k; // 0-indexed

        // first character
        res += ('a' + k / block);
        k %= block;

        for (int i = 1; i < n; ++i)
        {
            block /= 2;
            int idx = k / block;
            k %= block;
            // pick the idx-th char that differs from res.back()
            for (char c = 'a'; c <= 'c'; ++c)
            {
                if (c == res.back())
                    continue;
                if (idx-- == 0)
                {
                    res += c;
                    break;
                }
            }
        }
        return res;
    }
};