// Link: https://leetcode.com/problems/time-based-key-value-store/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) where n is the number of timestamps for a given key.
// SC: O(n) where n is the number of timestamps for a given key.
// Approach:
//   1. We will use an unordered_map to store the key-value pairs along with their timestamps.
//   2. For each key, we will store a vector of pairs where each pair contains the timestamp and the corresponding value.
//   3. When we set a value for a key, we will push the pair of timestamp and value into the vector for that key.
//   4. When we get a value for a key at a given timestamp, we will use upper_bound to find the first pair in the vector whose timestamp is greater than the given timestamp.
//   5. If such a pair exists, we will return the value of the previous pair; otherwise, we will return an empty string.
class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() { m.clear(); }

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = m.find(key);
        if (it == m.end())
            return "";
        auto &v = it->second;
        auto it2 = upper_bound(v.begin(), v.end(), timestamp,
                               [](int timestamp, const pair<int, string> &p)
                               {
                                   return timestamp < p.first;
                               });
        if (it2 == v.begin())
            return "";
        return prev(it2)->second;
    }
};