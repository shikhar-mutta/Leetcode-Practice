// Link: https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum|words| + |target|), SC: O(sum|words|)
// Approach: build an Aho-Corasick automaton (trie + failure links) from all words. Feeding
// target through it, the current node's depth at position j gives len[j] = the longest suffix
// of target[0..j] that is a prefix of some word. That match covers target[j-len[j]+1 .. j], so
// it lets a valid segment jump from "coverage count j-len[j]" up to "coverage count j+1". Reduce
// to the classic Jump Game II greedy over these (from, to) jumps to find the minimum segments,
// or -1 if target can't be fully covered.
class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        vector<array<int,26>> children;
        vector<int> fail;
        children.push_back({}); children[0].fill(-1);
        fail.push_back(0);
        vector<int> depth = {0};

        for (auto& w : words) {
            int cur = 0;
            for (char c : w) {
                int idx = c - 'a';
                if (children[cur][idx] == -1) {
                    children[cur][idx] = children.size();
                    children.push_back({}); children.back().fill(-1);
                    depth.push_back(depth[cur] + 1);
                }
                cur = children[cur][idx];
            }
        }

        // BFS to build failure links (with goto-function compression)
        fail.assign(children.size(), 0);
        queue<int> q;
        for (int c = 0; c < 26; c++) {
            if (children[0][c] == -1) { children[0][c] = 0; continue; } // root self-loops on missing chars
            fail[children[0][c]] = 0;
            q.push(children[0][c]);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int c = 0; c < 26; c++) {
                int v = children[u][c];
                if (v == -1) {
                    children[u][c] = children[fail[u]][c]; // already resolved, fail[u] has smaller depth
                } else {
                    fail[v] = children[fail[u]][c];
                    q.push(v);
                }
            }
        }

        int n = target.size();
        vector<long long> furthest(n+1, 0);
        int cur = 0;
        for (int j = 0; j < n; j++) {
            int idx = target[j] - 'a';
            cur = children[cur][idx]; // fully compressed, always a valid node
            int len = depth[cur];
            int start = j - len + 1; // coverage-count before this segment (= its start index)
            if (start < 0) start = 0;
            furthest[start] = max(furthest[start], (long long)(j + 1));
        }

        long long currentEnd = 0, nextEnd = 0;
        int jumps = 0, i = 0;
        while (currentEnd < n) {
            if (i > currentEnd) return -1;
            while (i <= currentEnd && i <= n) { nextEnd = max(nextEnd, furthest[i]); i++; }
            if (nextEnd <= currentEnd) return -1;
            jumps++;
            currentEnd = nextEnd;
        }
        return jumps;
    }
};
