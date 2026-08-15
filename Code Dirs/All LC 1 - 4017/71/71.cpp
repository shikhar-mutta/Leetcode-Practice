// Link: https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: split on '/', skip empty/".", pop the stack on "..", push everything else
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") continue;
            if (part == "..") { if (!stk.empty()) stk.pop_back(); }
            else stk.push_back(part);
        }
        string res;
        for (auto& p : stk) res += "/" + p;
        return res.empty() ? "/" : res;
    }
};
