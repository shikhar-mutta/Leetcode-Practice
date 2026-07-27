// Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: if numFriends==1 the whole word is the only piece. Otherwise
// every other friend needs at least 1 character, so the largest possible
// piece has length at most n-numFriends+1; the answer is the lexicographically
// largest substring achievable with that length cap starting anywhere.
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) return word;
        int maxLen = n - numFriends + 1;
        string best = "";
        for (int i = 0; i < n; i++) {
            string cand = word.substr(i, min(maxLen, n - i));
            if (cand > best) best = cand;
        }
        return best;
    }
};
