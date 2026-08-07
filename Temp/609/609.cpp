// Link: https://leetcode.com/problems/find-duplicate-file-in-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(total content length) SC: O(total content length)
// Approach: for each line, parse directory prefix and each "file(content)" token; group full file paths by content string in a map; return groups with size > 1.
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> groups;
        for (auto& line : paths) {
            stringstream ss(line);
            string dir;
            ss >> dir;
            string tok;
            while (ss >> tok) {
                size_t p = tok.find('(');
                string fname = tok.substr(0, p);
                string content = tok.substr(p+1, tok.size()-p-2);
                groups[content].push_back(dir + "/" + fname);
            }
        }
        vector<vector<string>> res;
        for (auto& [content, files] : groups)
            if (files.size() > 1) res.push_back(files);
        return res;
    }
};
