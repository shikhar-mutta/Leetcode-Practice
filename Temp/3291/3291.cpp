// Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int totalLen = 1;
        for (auto& w : words) totalLen += w.size();
        vector<array<int,26>> trie(totalLen);
        for (auto& row : trie) row.fill(-1);
        int nodeCount = 1;

        for (auto& w : words) {
            int cur = 0;
            for (char c : w) {
                int idx = c - 'a';
                if (trie[cur][idx] == -1) {
                    trie[cur][idx] = nodeCount++;
                }
                cur = trie[cur][idx];
            }
        }

        int n = target.size();
        vector<int> maxExtend(n, 0);
        for (int i = 0; i < n; i++) {
            int node = 0, len = 0;
            while (i + len < n) {
                int idx = target[i+len] - 'a';
                if (trie[node][idx] == -1) break;
                node = trie[node][idx];
                len++;
            }
            maxExtend[i] = len;
        }

        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < n; i++) {
            if (i > curEnd) return -1;
            farthest = max(farthest, i + maxExtend[i]);
            if (i == curEnd) {
                if (farthest == curEnd) return -1;
                jumps++;
                curEnd = farthest;
                if (curEnd >= n) return jumps;
            }
        }
        return curEnd >= n ? jumps : -1;
    }
};
