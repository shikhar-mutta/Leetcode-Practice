// Link: https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto& w : words) {
            if (w.size() >= pref.size() && w.compare(0, pref.size(), pref) == 0) count++;
        }
        return count;
    }
};
