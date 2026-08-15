// Link: https://leetcode.com/problems/string-transforms-into-another-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char,char> mapping;
        for (int i = 0; i < (int)str1.size(); i++) {
            char a = str1[i], b = str2[i];
            if (mapping.count(a) && mapping[a] != b) return false;
            mapping[a] = b;
        }
        unordered_set<char> usedInStr2(str2.begin(), str2.end());
        return usedInStr2.size() < 26;
    }
};
