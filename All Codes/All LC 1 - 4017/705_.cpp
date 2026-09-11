// Link: https://leetcode.com/problems/design-hashset/description/

#include <bits/stdc++.h>
using namespace std;

class MyHashSet
{
    static const int BUCKETS = 1009;

    // table → array of vectors
    // table[h] → one specific vector<int> (the bucket at index h)
    vector<int> table[BUCKETS];

    int hash(int key) { return key % BUCKETS; }

public:
    MyHashSet() {}

    void add(int key)
    {
        int h = hash(key);
        for (int x : table[h])
            if (x == key)
                return;
        // key already exists, do not add it again
        table[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        auto &bucket = table[h];
        // remove all occurrences of key from the bucket
        bucket.erase(std::remove(bucket.begin(), bucket.end(), key), bucket.end());
    }

    bool contains(int key)
    {
        int h = hash(key);
        for (int x : table[h])
            if (x == key) // key found in the bucket
                return true;
        return false;
    }

    //     bitset<1000001> bits;

    // public:
    //     MyHashSet() {}
    //     void add(int key) { bits.set(key); }
    //     void remove(int key) { bits.reset(key); }
    //     bool contains(int key) { return bits.test(key); }
};

using Solution = MyHashSet;
