// Link: https://leetcode.com/problems/partition-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: greedily extend the current segment; as soon as it hasn't
// been seen before, cut it off, record it as seen, and start a new
// segment. Per the official examples, any leftover partial segment at
// the end that never became "new" (i.e. only ever matched an already-
// seen segment) is simply dropped, not appended.
class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_set<string> seen;
        vector<string> result;
        string cur;
        for (char c : s) {
            cur += c;
            if (!seen.count(cur)) {
                seen.insert(cur);
                result.push_back(cur);
                cur.clear();
            }
        }
        return result;
    }
};
