// Link: https://leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

// All operations O(1). For each frequency we keep a list of keys in LRU order
// (most-recent at front), plus maps from key -> value, key -> freq, and
// key -> its iterator in the freq list. minFreq tracks the bucket to evict from.
class LFUCache {
    int cap, minFreq;
    unordered_map<int,int> keyToVal, keyToFreq;
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

    void touch(int key) {                 // bump a key's frequency by one
        int f = keyToFreq[key];
        freqToKeys[f].erase(keyToIter[key]);
        if (freqToKeys[f].empty()) {
            freqToKeys.erase(f);
            if (minFreq == f) minFreq++;
        }
        int nf = ++keyToFreq[key];
        freqToKeys[nf].push_front(key);
        keyToIter[key] = freqToKeys[nf].begin();
    }

public:
    LFUCache(int capacity) : cap(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyToVal.count(key)) return -1;
        touch(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        if (keyToVal.count(key)) {
            keyToVal[key] = value;
            touch(key);
            return;
        }
        if ((int)keyToVal.size() >= cap) {           // evict LFU (LRU as tiebreak)
            int evict = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToVal.erase(evict);
            keyToFreq.erase(evict);
            keyToIter.erase(evict);
        }
        keyToVal[key] = value;
        keyToFreq[key] = 1;
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
