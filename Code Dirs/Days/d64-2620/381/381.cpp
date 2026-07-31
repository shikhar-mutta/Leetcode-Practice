// Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized for insert/remove/getRandom  SC: O(n)
//  Approach: store values in a vector plus a hashmap from value to the
//  set of indices it occupies. remove() swaps the chosen index's element
//  with the last element (fixing up index sets) then pops, giving O(1)
//  removal while getRandom() is a uniform pick from the vector.
class RandomizedCollection
{
    vector<int> v;
    unordered_map<int, unordered_set<int>> mp;

public:
    RandomizedCollection() {}

    bool insert(int val)
    {
        bool ok = !mp.count(val) || mp[val].empty();

        mp[val].insert(v.size());
        v.push_back(val);

        return ok;
    }

    bool remove(int val)
    {
        if (!mp.count(val) || mp[val].empty())
            return false;

        int idx = *mp[val].begin();

        mp[val].erase(idx);

        int last = v.back();
        v[idx] = last;

        mp[last].insert(idx);
        mp[last].erase(v.size() - 1);

        v.pop_back();

        return true;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }
};