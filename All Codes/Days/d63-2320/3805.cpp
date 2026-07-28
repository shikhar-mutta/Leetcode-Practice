// Link: https://leetcode.com/problems/count-caesar-cipher-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of word lengths) SC: O(sum of word lengths)
// Approach: two words are Caesar-shift equivalent iff the sequence of
// consecutive-letter differences (each char minus the word's first char,
// mod 26) is identical. Build this shift-invariant signature per word,
// group by signature, and sum C(count,2) per group.
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> groups;
        for (auto& w : words) {
            string sig(w.size(), '0');
            for (int i = 0; i < (int)w.size(); i++) {
                int d = ((w[i] - w[0]) % 26 + 26) % 26;
                sig[i] = 'a' + d;
            }
            groups[sig]++;
        }
        long long ans = 0;
        for (auto& [k, c] : groups) ans += c * (c - 1) / 2;
        return ans;
    }
};
