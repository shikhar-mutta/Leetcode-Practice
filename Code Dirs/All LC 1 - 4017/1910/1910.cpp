// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        for (char c : s) {
            res += c;
            if (res.size() >= part.size() && res.compare(res.size() - part.size(), part.size(), part) == 0) {
                res.erase(res.size() - part.size());
            }
        }
        return res;
    }
};
