// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        string best = s;
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            best = min(best, cur);

            string added = cur;
            for (int i = 1; i < (int)added.size(); i += 2) {
                added[i] = '0' + (added[i] - '0' + a) % 10;
            }
            if (!visited.count(added)) { visited.insert(added); q.push(added); }

            string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!visited.count(rotated)) { visited.insert(rotated); q.push(rotated); }
        }
        return best;
    }
};
