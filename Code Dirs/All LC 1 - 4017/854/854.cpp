// Link: https://leetcode.com/problems/k-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s1);
        visited.insert(s1);
        int steps = 0;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                string cur = q.front(); q.pop();
                int i = 0;
                while (cur[i] == s2[i]) i++;
                for (int j = i + 1; j < (int)cur.size(); j++) {
                    if (cur[j] == s2[j] || cur[j] != s2[i]) continue;
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
        return -1;
    }
};
