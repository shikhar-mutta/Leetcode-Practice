// Link: https://leetcode.com/problems/truncate-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int count = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ' ') {
                count++;
                if (count == k) return s.substr(0, i);
            }
        }
        return s;
    }
};
