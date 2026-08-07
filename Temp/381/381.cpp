// Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for insert/remove/getRandom  SC: O(n)
// Approach: vector for O(1) random access + hashmap val->set of indices;
// remove swaps target index with the last element's index before popping
class RandomizedCollection {
    vector<int> vals;
    unordered_map<int, unordered_set<int>> idx;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool isNew = idx[val].empty();
        idx[val].insert(vals.size());
        vals.push_back(val);
        return isNew;
    }

    bool remove(int val) {
        if (idx[val].empty()) return false;
        int i = *idx[val].begin();
        idx[val].erase(i);
        int last = vals.back();
        vals[i] = last;
        if (i != (int)vals.size() - 1) {
            idx[last].erase(vals.size() - 1);
            idx[last].insert(i);
        }
        vals.pop_back();
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
