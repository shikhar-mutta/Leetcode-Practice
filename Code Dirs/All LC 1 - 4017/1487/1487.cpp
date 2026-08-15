// Link: https://leetcode.com/problems/making-file-names-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> used;
        vector<string> res;
        for (auto& name : names) {
            if (!used.count(name)) {
                res.push_back(name);
                used[name] = 1;
            } else {
                int k = used[name];
                string candidate;
                while (true) {
                    candidate = name + "(" + to_string(k) + ")";
                    if (!used.count(candidate)) break;
                    k++;
                }
                used[name] = k + 1;
                res.push_back(candidate);
                used[candidate] = 1;
            }
        }
        return res;
    }
};
