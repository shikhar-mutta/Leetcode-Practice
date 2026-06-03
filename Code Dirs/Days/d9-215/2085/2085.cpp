// Link: https://leetcode.com/problems/count-common-words-with-one-occurrence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Using a single unordered_map TC: O(n + m) SC: O(n + m)
    // Better than Approach 2: both counts stored as a pair in one map entry,
    // so the final loop needs no second hash lookup — better cache locality
    // and fewer hash computations overall.
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        std::unordered_map<string, std::pair<int, int>> map;

        for (const auto &word : words1)
        {
            map[word].first++;
        }
        for (const auto &word : words2)
        {
            map[word].second++;
        }
        int count{0};
        for (const auto &[key, val] : map)
        {
            if (val.first == 1 && val.second == 1)
                ++count;
        }
        return count;
    }

    // // Approach 2: Using two unordered_maps TC: O(n + m) SC: O(n + m)
    // int countWords(vector<string> &words1, vector<string> &words2)
    // {
    //     unordered_map<string, int> m1, m2;
    //     for (auto &s : words1)
    //         m1[s]++;
    //     for (auto &s : words2)
    //         m2[s]++;
    //     int ans = 0;
    //     for (auto &[s, c] : m1)
    //         if (c == 1 && m2.count(s) && m2.at(s) == 1)
    //             ans++;
    //     return ans;
    // }
};
