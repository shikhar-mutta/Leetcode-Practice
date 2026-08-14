// Link: https://leetcode.com/problems/minimize-string-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char> distinct(s.begin(), s.end());
        return distinct.size();
    }
};
