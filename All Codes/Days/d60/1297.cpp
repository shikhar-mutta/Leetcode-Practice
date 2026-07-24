// Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n) where n is the size of the string
// Approach:
// 1. We can use a rolling hash approach to solve this problem. We can use a hash function to compute the hash value of each substring of length minSize. We can use a hash map to keep track of the frequency of each hash value. We can also use a frequency array to keep track of the number of distinct characters in the current substring. We can iterate through the string and update the hash value and the frequency array for each substring of length minSize. If the number of distinct characters in the current substring is less than or equal to maxLetters, we can update the frequency of the current hash value in the hash map.
// 2. We can keep track of the maximum frequency of any hash value in a variable and return it as the result.
class Solution
{
private:
    using ull = unsigned long long;
    static constexpr ull BASE = 29;
    static ull pow(ull b, int p)
    {
        ull res = 1;
        while (p)
        {
            if (p & 1)
                res = res * b;
            b = b * b;
            p >>= 1;
        }
        return res;
    }

public:
    int maxFreq(string &s, int maxLetters, int minSize, int maxSize)
    {
        int n = s.size();
        int sz = minSize;
        int freq[26]{};
        int num = 0;
        ull accHash = 0, preHash = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (!(freq[s[i] - 'a']++))
                ++num;
            accHash = accHash * BASE + (s[i] - 'a');
        }
        unordered_map<ull, int> strFreq;
        int res = 0;
        if (num <= maxLetters)
        {
            strFreq[accHash] = 1;
            res = 1;
        }
        ull p = pow(BASE, sz);
        for (int i = sz; i < n; ++i)
        {
            if (!(freq[s[i] - 'a']++))
                ++num;
            if (!(--freq[s[i - sz] - 'a']))
                --num;
            accHash = accHash * BASE + (s[i] - 'a');
            preHash = preHash * BASE + (s[i - sz] - 'a');
            ull hash = accHash - preHash * p;
            if (num <= maxLetters)
            {
                res = max(res, ++strFreq[hash]);
            }
        }
        return res;
    }
};