// Link: https://leetcode.com/problems/split-concatenated-strings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * L)  SC: O(n * L)
// Approach: for each word, try reversing it and splitting the concatenation
// at that word's boundary; concat = prefix-before + (word's suffix..end +
// start..word's prefix) rearranged so the chosen word is first, take max
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        vector<string> best(strs.size());
        for (int i = 0; i < (int)strs.size(); i++) {
            string rev = strs[i];
            reverse(rev.begin(), rev.end());
            best[i] = max(strs[i], rev);
        }

        string result;
        for (int i = 0; i < (int)strs.size(); i++) {
            for (string cand : {strs[i], string(strs[i].rbegin(), strs[i].rend())}) {
                for (int cut = 0; cut <= (int)cand.size(); cut++) {
                    string s = cand.substr(cut) ;
                    for (int j = i + 1; j < (int)strs.size(); j++) s += best[j];
                    for (int j = 0; j < i; j++) s += best[j];
                    s += cand.substr(0, cut);
                    result = max(result, s);
                }
            }
        }
        return result;
    }
};
