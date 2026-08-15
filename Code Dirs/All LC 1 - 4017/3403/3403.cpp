// Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        int maxLen = n - numFriends + 1;
        string best = "";
        for (int i = 0; i < n; i++) {
            int len = min(maxLen, n - i);
            string cand = word.substr(i, len);
            if (cand > best) best = cand;
        }
        return best;
    }
};
