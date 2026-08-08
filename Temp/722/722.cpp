// Link: https://leetcode.com/problems/remove-comments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total chars) SC: O(total chars)
// Approach: scan character by character tracking block-comment state; outside a block comment, detect "//" (skip rest of line) or "/*" (enter block comment); inside a block comment, look for "*/" to exit. Accumulate non-comment characters into the current line buffer, flushing to result at line boundaries (only if non-empty).
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool inBlock = false;
        string buf;
        for (auto& line : source) {
            int i = 0, n = line.size();
            while (i < n) {
                if (!inBlock && i+1 < n && line[i]=='/' && line[i+1]=='/') {
                    break; // rest of line is a line comment
                } else if (!inBlock && i+1 < n && line[i]=='/' && line[i+1]=='*') {
                    inBlock = true;
                    i += 2;
                } else if (inBlock && i+1 < n && line[i]=='*' && line[i+1]=='/') {
                    inBlock = false;
                    i += 2;
                } else if (!inBlock) {
                    buf += line[i];
                    i++;
                } else {
                    i++;
                }
            }
            if (!inBlock && !buf.empty()) {
                res.push_back(buf);
                buf.clear();
            }
        }
        return res;
    }
};
