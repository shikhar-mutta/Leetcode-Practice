// Link: https://leetcode.com/problems/shuffle-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res(s.size(), ' ');
        for (int i = 0; i < (int)s.size(); i++) res[indices[i]] = s[i];
        return res;
    }
};
