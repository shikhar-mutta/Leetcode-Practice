// Link: https://leetcode.com/problems/lru-cache/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) per op  SC: O(capacity)
// Approach: doubly linked list (most-recent at front) + hash map key->list iterator;
// touching a key on get/put splices it to the front, eviction drops the list's back
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        order.splice(order.begin(), order, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            order.splice(order.begin(), order, it->second);
            return;
        }
        if ((int)order.size() == cap) {
            int lruKey = order.back().first;
            order.pop_back();
            pos.erase(lruKey);
        }
        order.push_front({key, value});
        pos[key] = order.begin();
    }

private:
    int cap;
    list<pair<int,int>> order;
    unordered_map<int, list<pair<int,int>>::iterator> pos;
};
