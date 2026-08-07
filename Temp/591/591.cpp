// Link: https://leetcode.com/problems/tag-validator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) worst case due to substr SC: O(n)
// Approach: scan left to right; use a tag-name stack. Handle CDATA sections (skip until ]]>) verbatim, close tags (pop matching), open tags (validate name 1-9 uppercase letters, push), and plain text (must not contain '<' outside tags). Track whether root wrapping is satisfied.
class Solution {
public:
    bool isValid(string code) {
        int n = code.size();
        vector<string> stk;
        int i = 0;
        bool hasTag = false;
        while (i < n) {
            if (stk.empty() && hasTag) return false; // extra content after closed root
            if (code[i] == '<') {
                if (stk.empty() && i != 0) return false;
                if (i+1 < n && code[i+1] == '/') {
                    // closing tag
                    int j = code.find('>', i);
                    if (j == string::npos) return false;
                    string name = code.substr(i+2, j-(i+2));
                    if (!validName(name)) return false;
                    if (stk.empty() || stk.back() != name) return false;
                    stk.pop_back();
                    i = j+1;
                } else if (i+8 < n && code.substr(i, 9) == "<![CDATA[") {
                    if (stk.empty()) return false;
                    size_t j = code.find("]]>", i+9);
                    if (j == string::npos) return false;
                    i = j+3;
                } else {
                    // opening tag
                    int j = code.find('>', i);
                    if (j == string::npos) return false;
                    string name = code.substr(i+1, j-(i+1));
                    if (!validName(name)) return false;
                    stk.push_back(name);
                    hasTag = true;
                    i = j+1;
                }
            } else {
                if (stk.empty()) return false;
                i++;
            }
        }
        return stk.empty() && hasTag;
    }

    bool validName(const string& name) {
        if (name.size() < 1 || name.size() > 9) return false;
        for (char c : name) if (!isupper(c)) return false;
        return true;
    }
};
