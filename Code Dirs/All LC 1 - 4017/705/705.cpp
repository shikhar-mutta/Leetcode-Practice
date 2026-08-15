// Link: https://leetcode.com/problems/design-hashset/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) average per op SC: O(n)
// Approach: backed by a hash set.
class MyHashSet {
    unordered_set<int> data;
public:
    MyHashSet() {}
    void add(int key) { data.insert(key); }
    void remove(int key) { data.erase(key); }
    bool contains(int key) { return data.count(key) > 0; }
};
