// Link: https://leetcode.com/problems/queries-on-a-permutation-with-key/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> perm(m);
        iota(perm.begin(), perm.end(), 1);
        vector<int> res;
        for (int q : queries) {
            int idx = find(perm.begin(), perm.end(), q) - perm.begin();
            res.push_back(idx);
            perm.erase(perm.begin() + idx);
            perm.insert(perm.begin(), q);
        }
        return res;
    }
};
