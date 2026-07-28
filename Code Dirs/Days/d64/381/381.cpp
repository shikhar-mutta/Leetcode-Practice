// Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1) amortized for insert/remove/getRandom  SC: O(n)
// Approach: store values in a vector plus a hashmap from value to the
// set of indices it occupies. remove() swaps the chosen index's element
// with the last element (fixing up index sets) then pops, giving O(1)
// removal while getRandom() is a uniform pick from the vector.
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
        auto it = idx.find(val);
        if (it == idx.end() || it->second.empty()) return false;
        int i = *it->second.begin();
        it->second.erase(i);
        int last = vals.back();
        vals[i] = last;
        if (i != (int)vals.size() - 1) {
            idx[last].erase((int)vals.size() - 1);
            idx[last].insert(i);
        }
        vals.pop_back();
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
