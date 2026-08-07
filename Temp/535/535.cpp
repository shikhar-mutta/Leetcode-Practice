// Link: https://leetcode.com/problems/encode-and-decode-tinyurl/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized  SC: O(n)
// Approach: hashmap from a short incrementing key to the original URL
class Solution {
    unordered_map<string, string> store;
    int counter = 0;

public:
    string encode(string longUrl) {
        string key = to_string(counter++);
        store[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

    string decode(string shortUrl) {
        string key = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return store[key];
    }
};
