// Link: https://leetcode.com/problems/partition-labels/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: precompute last occurrence index of each char; greedily extend partition end to the max last-occurrence among chars seen so far; close partition when position reaches end.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        for (int i = 0; i < (int)s.size(); i++) last[s[i]-'a'] = i;
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            end = max(end, last[s[i]-'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};
