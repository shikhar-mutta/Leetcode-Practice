// Link: https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        set<string> pairs;
        for (int i = 0; i + 1 < (int)s.size(); i++) pairs.insert(s.substr(i, 2));
        for (auto& p : pairs) {
            string rev = p;
            reverse(rev.begin(), rev.end());
            if (pairs.count(rev)) return true;
        }
        return false;
    }
};
