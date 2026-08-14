// Link: https://leetcode.com/problems/decode-the-message/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mapping;
        char next = 'a';
        for (char c : key) {
            if (c == ' ') continue;
            if (!mapping.count(c)) {
                mapping[c] = next;
                next++;
            }
        }
        string res;
        for (char c : message) {
            if (c == ' ') res += ' ';
            else res += mapping[c];
        }
        return res;
    }
};
