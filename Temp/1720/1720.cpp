// Link: https://leetcode.com/problems/decode-xored-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for (int x : encoded) res.push_back(res.back() ^ x);
        return res;
    }
};
