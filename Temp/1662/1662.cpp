// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a, b;
        for (auto& s : word1) a += s;
        for (auto& s : word2) b += s;
        return a == b;
    }
};
