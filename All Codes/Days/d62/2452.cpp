// Link: https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(q * d * L) where q = queries.size(), d = dictionary.size(), L = word length
// SC: O(1) extra (excluding the output)
// Approach: all words share the same fixed length, so an "edit" here is
// just a single-character substitution. For each query, check every
// dictionary word by counting mismatched positions (bailing out once it
// exceeds 2); the query qualifies as soon as any dictionary word is
// within 2 mismatches.
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> res;
        for (auto& q : queries) {
            for (auto& d : dictionary) {
                int diff = 0;
                for (int i = 0; i < q.size(); ++i) {
                    if (q[i] != d[i])
                        ++diff;
                    if (diff > 2)
                        break;
                }
                if (diff <= 2) {
                    res.push_back(q);
                    break; // one match suffices
                }
            }
        }
        return res;
    }
};
