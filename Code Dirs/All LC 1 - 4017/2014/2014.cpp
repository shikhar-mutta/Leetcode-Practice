// Link: https://leetcode.com/problems/longest-subsequence-repeated-k-times/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(const string& s, const string& seq, int k) {
        int n = s.size(), m = seq.size();
        if (m == 0) return true;
        int j = 0, cnt = 0;
        for (int i = 0; i < n && cnt < k; i++) {
            if (s[i] == seq[j]) {
                j++;
                if (j == m) { cnt++; j = 0; }
            }
        }
        return cnt == k;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        string letters;
        for (int i = 0; i < 26; i++) if (freq[i] >= k) letters += (char)('a' + i);

        queue<string> q;
        q.push("");
        string ans = "";
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (char c : letters) {
                string nxt = cur + c;
                if (check(s, nxt, k)) {
                    q.push(nxt);
                    if (nxt.size() > ans.size() || (nxt.size() == ans.size() && nxt > ans)) ans = nxt;
                }
            }
        }
        return ans;
    }
};
