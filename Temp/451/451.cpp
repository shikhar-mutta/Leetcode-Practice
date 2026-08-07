// Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: count frequencies, sort characters descending by count, output
// each char repeated count times
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        vector<pair<int,char>> items;
        for (auto& [c, cnt] : freq) items.push_back({cnt, c});
        sort(items.begin(), items.end(), greater<>());

        string res;
        for (auto& [cnt, c] : items) res += string(cnt, c);
        return res;
    }
};
