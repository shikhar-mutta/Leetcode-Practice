// Link: https://leetcode.com/problems/minimum-genetic-mutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * len * 4)  SC: O(n)
// Approach: BFS over the gene bank, trying single-character mutations at
// each step, only moving to genes present in the bank
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (!bankSet.count(endGene)) return -1;

        unordered_set<string> visited{startGene};
        queue<string> q;
        q.push(startGene);
        int steps = 0;
        string chars = "ACGT";

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front(); q.pop();
                if (cur == endGene) return steps;
                for (int pos = 0; pos < (int)cur.size(); pos++) {
                    char orig = cur[pos];
                    for (char c : chars) {
                        if (c == orig) continue;
                        cur[pos] = c;
                        if (bankSet.count(cur) && !visited.count(cur)) {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[pos] = orig;
                }
            }
            steps++;
        }
        return -1;
    }
};
