// Link: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> res;
        for (auto& f : folder) {
            if (res.empty() || !(f.size() > res.back().size() && f.substr(0, res.back().size()) == res.back() && f[res.back().size()] == '/')) {
                res.push_back(f);
            }
        }
        return res;
    }
};
