// Link: https://leetcode.com/problems/sort-the-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return heights[a] > heights[b]; });
        vector<string> res(n);
        for (int i = 0; i < n; i++) res[i] = names[idx[i]];
        return res;
    }
};
