// Link: https://leetcode.com/problems/iterator-for-combination/description/

#include <bits/stdc++.h>
using namespace std;

class CombinationIterator {
public:
    vector<string> combos;
    int idx = 0;

    CombinationIterator(string characters, int combinationLength) {
        string cur;
        function<void(int)> dfs = [&](int start) {
            if ((int)cur.size() == combinationLength) {
                combos.push_back(cur);
                return;
            }
            for (int i = start; i < (int)characters.size(); i++) {
                cur += characters[i];
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
    }

    string next() {
        return combos[idx++];
    }

    bool hasNext() {
        return idx < (int)combos.size();
    }
};
