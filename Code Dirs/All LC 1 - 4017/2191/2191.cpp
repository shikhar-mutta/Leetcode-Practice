// Link: https://leetcode.com/problems/sort-the-jumbled-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mapNum(vector<int>& mapping, int x) {
        if (x == 0) return mapping[0];
        string s = to_string(x);
        string res;
        for (char c : s) res += ('0' + mapping[c - '0']);
        return stoi(res);
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        vector<int> mapped(n);
        for (int i = 0; i < n; i++) mapped[i] = mapNum(mapping, nums[i]);
        stable_sort(idx.begin(), idx.end(), [&](int a, int b) { return mapped[a] < mapped[b]; });
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = nums[idx[i]];
        return res;
    }
};
