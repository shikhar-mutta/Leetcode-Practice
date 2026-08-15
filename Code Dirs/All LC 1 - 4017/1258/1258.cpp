// Link: https://leetcode.com/problems/synonymous-sentences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string,string> parent;

    string find(string x) {
        if (!parent.count(x)) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string a, string b) {
        parent[find(a)] = find(b);
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto& s : synonyms) unite(s[0], s[1]);

        unordered_map<string, set<string>> groups;
        for (auto& [word, _] : parent) {
            groups[find(word)].insert(word);
        }

        stringstream ss(text);
        string word;
        vector<vector<string>> options;
        while (ss >> word) {
            if (parent.count(word)) {
                auto& g = groups[find(word)];
                options.push_back(vector<string>(g.begin(), g.end()));
            } else {
                options.push_back({word});
            }
        }

        vector<string> res;
        vector<string> cur;
        function<void(int)> dfs = [&](int idx) {
            if (idx == (int)options.size()) {
                string sentence;
                for (int i = 0; i < (int)cur.size(); i++) {
                    if (i) sentence += " ";
                    sentence += cur[i];
                }
                res.push_back(sentence);
                return;
            }
            for (auto& w : options[idx]) {
                cur.push_back(w);
                dfs(idx + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        sort(res.begin(), res.end());
        return res;
    }
};
