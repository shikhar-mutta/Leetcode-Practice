// Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: small (candidate length bounded by n/k <= 7), exponential in that bound
// SC: O(candidates)
// Approach: only characters with frequency >= k can appear in the answer.
// BFS by length: start from single valid chars, extend each surviving
// candidate with every valid char, keep those whose string repeated k times
// is a subsequence of s. The last surviving level gives the (lexicographically
// largest, via sorted-descending generation) longest answer.
class Solution {
    bool isKSub(string& s, string& cand, int k) {
        int si = 0, matched = 0;
        int n = s.size(), m = cand.size();
        for (int i = 0; i < n && matched < k; i++) {
            if (s[i] == cand[si]) {
                si++;
                if (si == m) { si = 0; matched++; }
            }
        }
        return matched >= k;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        vector<char> valid;
        for (int c = 25; c >= 0; c--) if (freq[c] >= k) valid.push_back('a' + c);

        vector<string> cur;
        for (char c : valid) cur.push_back(string(1, c));
        string best = "";
        while (!cur.empty()) {
            vector<string> next;
            for (auto& cand : cur) {
                if (isKSub(s, cand, k)) {
                    if (cand.size() > best.size()) best = cand;
                    for (char c : valid) next.push_back(cand + c);
                }
            }
            cur = next;
        }
        return best;
    }
};
