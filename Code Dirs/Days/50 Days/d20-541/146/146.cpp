// Link: https://leetcode.com/problems/lru-cache/description/

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int capacity;
    list<pair<int,int>> lst;                          // front = MRU, back = LRU
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (!mp.count(key)) return -1;
        lst.splice(lst.begin(), lst, mp[key]);        // move to front, O(1)
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.count(key)) {
            lst.splice(lst.begin(), lst, mp[key]);    // move to front
            mp[key]->second = value;
        } else {
            if ((int)mp.size() == capacity) {
                mp.erase(lst.back().first);           // evict LRU
                lst.pop_back();
            }
            lst.emplace_front(key, value);
            mp[key] = lst.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */