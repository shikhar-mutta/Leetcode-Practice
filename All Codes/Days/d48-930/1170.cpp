// Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m), SC: O(1)
    // Approach:
    // 1. For each word in words, we can calculate f(word) and store the count of each f(word) in a vector cnt, where cnt[v] is the number of words with f(word) == v. Since the length of each word is at most 10, we can use a vector of size 12 (to account for f(word) values from 0 to 10).
    // 2. We can then compute the suffix sum of cnt, so that cnt[v] will represent the number of words with f(word) >= v.
    // 3. Finally, for each query in queries, we can calculate f(query) and use the cnt vector to find the number of words in words that have a strictly greater f(word) value than f(query).
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        auto f = [](const string &s)
        {
            char mn = *min_element(s.begin(), s.end());
            return (int)count(s.begin(), s.end(), mn);
        };

        // cnt[v] = number of words with f(word) == v (word length <= 10)
        vector<int> cnt(12, 0);
        for (auto &w : words)
            cnt[f(w)]++;
        // suffix sum: cnt[v] = number of words with f(word) >= v
        for (int v = 10; v >= 0; v--)
            cnt[v] += cnt[v + 1];

        vector<int> res;
        res.reserve(queries.size());
        for (auto &q : queries)
            res.push_back(cnt[f(q) + 1]);
        return res;
    }
};
