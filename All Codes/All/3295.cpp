// Link: https://leetcode.com/problems/report-spam-message/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+m), SC: O(m)
// Approach: Put bannedWords in a hash set, then scan message counting how
// many words are banned; the message is spam once 2 such words are found
// (early-exit on the second hit).
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int n = message.size(), m = bannedWords.size();
        unordered_set<string> words;
        words.max_load_factor(0.7f);
        words.reserve(m);
        words.insert(bannedWords.begin(), bannedWords.end());
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (words.contains(message[i])) {
                ++cnt;
                if (cnt == 2)
                    return 1;
            }
        }
        return (cnt >= 2);
    }
};

static const int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
