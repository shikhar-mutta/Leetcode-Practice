// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for insert/remove/getRandom  SC: O(n)
// Approach: vector for O(1) random access + hashmap val->index; remove
// swaps target with the last element before popping to keep O(1)
class RandomizedSet {
    vector<int> vals;
    unordered_map<int, int> idx;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (idx.count(val)) return false;
        idx[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end()) return false;
        int i = it->second;
        int last = vals.back();
        vals[i] = last;
        idx[last] = i;
        vals.pop_back();
        idx.erase(val);
        return true;
    }

    int getRandom() {
        return vals[rand() % vals.size()];
    }
};
