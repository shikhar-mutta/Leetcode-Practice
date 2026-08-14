// Link: https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<set<string>> wordSubs(n);
        for (int i = 0; i < n; i++) {
            string& w = arr[i];
            for (int l = 0; l < (int)w.size(); l++)
                for (int len = 1; l + len <= (int)w.size(); len++)
                    wordSubs[i].insert(w.substr(l, len));
        }
        unordered_map<string, int> tally;
        for (int i = 0; i < n; i++)
            for (auto& s : wordSubs[i]) tally[s]++;

        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string best = "";
            for (auto& s : wordSubs[i]) {
                if (tally[s] == 1) {
                    if (best.empty() || s.size() < best.size() || (s.size() == best.size() && s < best))
                        best = s;
                }
            }
            res[i] = best;
        }
        return res;
    }
};
