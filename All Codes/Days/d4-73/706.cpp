// Link: https://leetcode.com/problems/design-hashmap/description/

#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
    map<int, int> mp;

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        mp[key] = value;
    }

    int get(int key)
    {
        return mp.find(key) != mp.end() ? mp[key] : -1;
    }

    void remove(int key)
    {
        mp.erase(key);
    }
};
