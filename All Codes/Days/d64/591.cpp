// Link: https://leetcode.com/problems/tag-validator/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: single left-to-right scan with a stack of open tag names.
// At each '<': check for CDATA (skip verbatim to the first "]]>"), an
// end tag (must match stack top, pop, and if the stack empties nothing
// may follow), or a start tag (validate name, push). Any character
// outside an open tag, or leftover unbalanced stack, invalidates.
class Solution {
    bool validTagName(const string& t) {
        if (t.empty() || t.size() > 9) return false;
        for (char c : t) if (!isupper(c)) return false;
        return true;
    }
public:
    bool isValid(string code) {
        int n = code.size();
        stack<string> tags;
        bool hasTag = false;
        int i = 0;
        while (i < n) {
            if (tags.empty() && i > 0) return false;
            if (code[i] == '<') {
                if (code.compare(i, 9, "<![CDATA[") == 0) {
                    if (tags.empty()) return false;
                    size_t j = code.find("]]>", i + 9);
                    if (j == string::npos) return false;
                    i = j + 3;
                } else if (i + 1 < n && code[i + 1] == '/') {
                    size_t j = code.find('>', i);
                    if (j == string::npos) return false;
                    string tag = code.substr(i + 2, j - i - 2);
                    if (!validTagName(tag)) return false;
                    if (tags.empty() || tags.top() != tag) return false;
                    tags.pop();
                    i = j + 1;
                    if (tags.empty() && i != n) return false;
                } else {
                    size_t j = code.find('>', i);
                    if (j == string::npos) return false;
                    string tag = code.substr(i + 1, j - i - 1);
                    if (!validTagName(tag)) return false;
                    tags.push(tag);
                    hasTag = true;
                    i = j + 1;
                }
            } else {
                if (tags.empty()) return false;
                i++;
            }
        }
        return tags.empty() && hasTag;
    }
};
