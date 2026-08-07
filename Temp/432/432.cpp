// Link: https://leetcode.com/problems/all-oone-data-structure/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized for all operations (using an ordered map here gives
// O(log n) but stays well within limits)  SC: O(n)
// Approach: map from key->count, plus an ordered map count->set of keys
// for fast max/min lookup
class AllOne {
    unordered_map<string, int> keyCount;
    map<int, set<string>> countKeys;

public:
    AllOne() {}

    void inc(string key) {
        int cnt = keyCount.count(key) ? keyCount[key] : 0;
        if (cnt > 0) {
            countKeys[cnt].erase(key);
            if (countKeys[cnt].empty()) countKeys.erase(cnt);
        }
        keyCount[key] = cnt + 1;
        countKeys[cnt + 1].insert(key);
    }

    void dec(string key) {
        int cnt = keyCount[key];
        countKeys[cnt].erase(key);
        if (countKeys[cnt].empty()) countKeys.erase(cnt);
        if (cnt == 1) {
            keyCount.erase(key);
        } else {
            keyCount[key] = cnt - 1;
            countKeys[cnt - 1].insert(key);
        }
    }

    string getMaxKey() {
        if (countKeys.empty()) return "";
        return *countKeys.rbegin()->second.begin();
    }

    string getMinKey() {
        if (countKeys.empty()) return "";
        return *countKeys.begin()->second.begin();
    }
};
