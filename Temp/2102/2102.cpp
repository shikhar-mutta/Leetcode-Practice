// Link: https://leetcode.com/problems/sequentially-ordinal-rank-tracker/description/

#include <bits/stdc++.h>
using namespace std;

class SORTracker {
    struct Cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
    set<pair<int,string>, Cmp> locs;
    set<pair<int,string>, Cmp>::iterator it;
    bool started = false;
public:
    SORTracker() {}

    void add(string name, int score) {
        pair<int,string> p = {score, name};
        bool needDecrement = started && Cmp()(p, *it);
        locs.insert(p);
        if (needDecrement) --it;
    }

    string get() {
        if (!started) { it = locs.begin(); started = true; }
        else ++it;
        return it->second;
    }
};
