// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s) {
            if (!res.empty() && res.back() == c) res.pop_back();
            else res += c;
        }
        return res;
    }
};
