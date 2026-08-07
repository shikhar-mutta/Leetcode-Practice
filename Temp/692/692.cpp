// Link: https://leetcode.com/problems/top-k-frequent-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: count frequencies, sort unique words by (higher freq, then lexicographically smaller), take top k.
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> cnt;
        for (auto& w : words) cnt[w]++;
        vector<pair<string,int>> items(cnt.begin(), cnt.end());
        sort(items.begin(), items.end(), [](auto& a, auto& b){
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });
        vector<string> res;
        for (int i = 0; i < k; i++) res.push_back(items[i].first);
        return res;
    }
};
