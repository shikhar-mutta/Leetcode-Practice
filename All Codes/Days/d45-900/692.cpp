// Link: https://leetcode.com/problems/top-k-frequent-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn). SC: O(n).
// Approach: Count the frequency of each word using a hash map. Then, sort the words based on their frequency and lexicographical order. Finally, return the top k words.
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (auto &w : words)
            freq[w]++;

        vector<pair<string, int>> items(freq.begin(), freq.end());
        sort(items.begin(), items.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first; });

        vector<string> res;
        for (int i = 0; i < k; i++)
            res.push_back(items[i].first);
        return res;
    }
};
