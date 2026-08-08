// Link: https://leetcode.com/problems/largest-merge-of-two-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int i = 0, j = 0;
        while (i < (int)word1.size() && j < (int)word2.size()) {
            if (word1.substr(i) > word2.substr(j)) res += word1[i++];
            else res += word2[j++];
        }
        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};
