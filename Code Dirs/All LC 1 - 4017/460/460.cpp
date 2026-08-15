// Link: https://leetcode.com/problems/lfu-cache/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized for get/put  SC: O(capacity)
// Approach: hashmap key->(value,freq), frequency buckets each holding an
// ordered list of keys (front = least recently used within that freq),
// plus iterator map for O(1) removal; track minFreq for eviction
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int,int>> keyToValFreq; // key -> (value, freq)
    unordered_map<int, list<int>> freqToKeys;
    unordered_map<int, list<int>::iterator> keyToIter;

    void touch(int key) {
        int freq = keyToValFreq[key].second;
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        keyToValFreq[key].second++;
        freqToKeys[freq + 1].push_back(key);
        keyToIter[key] = prev(freqToKeys[freq + 1].end());
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (!keyToValFreq.count(key)) return -1;
        int val = keyToValFreq[key].first;
        touch(key);
        return val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (keyToValFreq.count(key)) {
            keyToValFreq[key].first = value;
            touch(key);
            return;
        }
        if ((int)keyToValFreq.size() >= capacity) {
            int evict = freqToKeys[minFreq].front();
            freqToKeys[minFreq].pop_front();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);
            keyToValFreq.erase(evict);
            keyToIter.erase(evict);
        }
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_back(key);
        keyToIter[key] = prev(freqToKeys[1].end());
        minFreq = 1;
    }
};
