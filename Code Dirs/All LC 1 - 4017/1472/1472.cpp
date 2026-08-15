// Link: https://leetcode.com/problems/design-browser-history/description/

#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    vector<string> history;
    int cur;

    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
    }

    void visit(string url) {
        history.resize(cur + 1);
        history.push_back(url);
        cur++;
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }

    string forward(int steps) {
        cur = min((int)history.size() - 1, cur + steps);
        return history[cur];
    }
};
