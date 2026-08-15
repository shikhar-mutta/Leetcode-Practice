// Link: https://leetcode.com/problems/map-sum-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the number of keys in the map and m is the length of the prefix. In the worst case, we may have to check all keys in the map to see if they start with the given prefix.
// SC: O(n) for storing the keys and values in the unordered_map.
// Approach:
// 1. We use an unordered_map to store the key-value pairs.
// 2. The insert function simply adds or updates the key-value pair in the map.
// 3. The sum function iterates through all the keys in the map and checks if they start with the given prefix. If they do, we add their corresponding values to the total sum.
// 4. Finally, we return the total sum of values for keys that start with the given prefix.
class MapSum
{
    unordered_map<string, int> map;

public:
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        map[key] = val;
    }

    int sum(string prefix)
    {
        int total = 0;
        for (auto &[k, v] : map)
        {
            if (k.compare(0, prefix.size(), prefix) == 0)
                total += v;
        }
        return total;
    }
};
