// Link: https://leetcode.com/problems/group-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k log k) where n is the number of strings in the input array and k is the maximum length of a string. For each string, we sort it which takes O(k log k) time.
// SC: O(n * k) for storing the result and the hash map, where n is the number of strings and k is the maximum length of a string. The hash map can store up to n keys, and each key can have a vector of strings with a total length of k
// Approach: We use a hash map to group anagrams together. For each string, we sort its characters to create a key. All strings that are anagrams of each other will have the same sorted key. We then store the original strings in a vector corresponding to their sorted key in the hash map. Finally, we collect all the grouped anagrams from the hash map and return them as a vector of vectors.
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto &[k, g] : groups)
            res.push_back(move(g));
        return res;
    }
};
