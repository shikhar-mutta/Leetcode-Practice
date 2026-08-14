// Link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        while (s.size() % k != 0) s += fill;
        vector<string> res;
        for (int i = 0; i < (int)s.size(); i += k) res.push_back(s.substr(i, k));
        return res;
    }
};
