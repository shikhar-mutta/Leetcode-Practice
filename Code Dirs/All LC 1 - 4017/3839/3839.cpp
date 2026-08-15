// Link: https://leetcode.com/problems/number-of-prefix-connected-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of word lengths) SC: O(n*k)
//  Approach: words with length < k are ignored; group the rest by their
//  first k characters and count groups with at least 2 members.
class Solution
{
public:
    inline unsigned long long
    hash(const void *data, size_t len,
         unsigned long long hash = 14695981039346656037ULL)
    {
        const unsigned char *s = static_cast<const unsigned char *>(data);
        while (len-- > 0)
            hash = 1099511628211ULL * (hash ^ *s++);
        return hash;
    }

    int prefixConnected(vector<string> &words, int k)
    {
        unordered_map<unsigned long long, int> count;

        for (const string &word : words)
        {
            if (word.length() < k)
                continue;

            count[hash(word.c_str(), k)]++;
        }

        int ret = 0;
        for (unordered_map<unsigned long long, int>::iterator it =
                 count.begin();
             it != count.end(); it++)
        {
            if (it->second > 1)
                ret++;
        }
        return ret;
    }
};