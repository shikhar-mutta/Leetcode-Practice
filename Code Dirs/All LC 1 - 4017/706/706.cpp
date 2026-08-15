// Link: https://leetcode.com/problems/design-hashmap/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) average per op SC: O(n)
// Approach: backed by a hash map.
class MyHashMap {
    unordered_map<int,int> data;
public:
    MyHashMap() {}
    void put(int key, int value) { data[key] = value; }
    int get(int key) {
        auto it = data.find(key);
        return it == data.end() ? -1 : it->second;
    }
    void remove(int key) { data.erase(key); }
};
