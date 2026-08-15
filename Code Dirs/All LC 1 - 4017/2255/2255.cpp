// Link: https://leetcode.com/problems/count-prefixes-of-a-given-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto& w : words) {
            if (w.size() <= s.size() && s.compare(0, w.size(), w) == 0) count++;
        }
        return count;
    }
};
