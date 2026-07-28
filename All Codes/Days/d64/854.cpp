// Link: https://leetcode.com/problems/k-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * n! ) worst case, pruned heavily in practice  SC: O(states)
// Approach: BFS where each state is a permutation of s1. To generate
// successors of a state, find its first mismatched position i (relative
// to s2), then swap s2[i] into any later position j where it fixes a
// mismatch (state[j]==s2[i]) — this greedy restriction (only ever fix
// the leftmost mismatch) avoids exploring the full swap space while
// still reaching the optimum.
class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s1);
        visited.insert(s1);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                string cur = q.front(); q.pop();
                int i = 0;
                while (cur[i] == s2[i]) i++;
                for (int j = i + 1; j < (int)cur.size(); j++) {
                    if (cur[j] == s2[i] && cur[j] != s2[j]) {
                        string next = cur;
                        swap(next[i], next[j]);
                        if (next == s2) return steps;
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
