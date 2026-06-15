// Link: https://leetcode.com/problems/design-browser-history/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for each operation, SC: O(n) for n calls to visit
class BrowserHistory {
    vector<string> hist; // hist[0..cur] is the back-stack, beyond cur is forward
    int cur;

public:
    BrowserHistory(string homepage) {
        hist.push_back(homepage);
        cur = 0;
    }

    void visit(string url) {
        hist.resize(cur + 1); // visiting clears all forward history
        hist.push_back(url);
        cur++;
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return hist[cur];
    }

    string forward(int steps) {
        cur = min((int)hist.size() - 1, cur + steps);
        return hist[cur];
    }
};
