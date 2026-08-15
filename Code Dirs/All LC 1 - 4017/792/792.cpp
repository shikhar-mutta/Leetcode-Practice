// Link: https://leetcode.com/problems/number-of-matching-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s| + sum(|words|)) SC: O(sum(|words|))
// Approach: bucket each word by the character it's currently waiting to match, keyed by first remaining char. Scan s once; for each char, advance all words in that bucket by one position, moving them to the bucket for their new next char (or counting them complete).
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string,int>>> buckets(26);
        for (auto& w : words) buckets[w[0]-'a'].push_back({w, 0});
        int count = 0;
        for (char c : s) {
            auto bucket = buckets[c-'a'];
            buckets[c-'a'].clear();
            for (auto& [w, idx] : bucket) {
                int ni = idx+1;
                if (ni == (int)w.size()) count++;
                else buckets[w[ni]-'a'].push_back({w, ni});
            }
        }
        return count;
    }
};
